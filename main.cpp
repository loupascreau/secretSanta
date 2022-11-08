/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:22:39 by lpascrea          #+#    #+#             */
/*   Updated: 2021/12/23 15:17:57 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassName.hpp"

int		init(void)
{
	int		nbr_players;
	std::cout << std::endl;
	std::cout << MAGEN << "[ Welcome to Secret Santa ] " << WHITE << std::endl;
	std::cout << std::endl;
	
	std::cout << "How many players are you ? ";
	std::cin >> nbr_players;

	std::cout << std::endl;
	std::cout << YELLOW<< "[ You are " << nbr_players << " players ] " << WHITE << std::endl;
	std::cout << std::endl;

	return nbr_players;
}

int		main(void)
{
	std::string	bufName;
	std::string	bufMail;
	int			i;
	int			nbr_players;
	int			random;
	int			nbr_gift;

	nbr_players = init();
	if (nbr_players < 3) {
		std::cout << "ERROR : you must be at least 3 players to play !" << std::endl;
		return 0;
	}
	ClassName	*players[nbr_players];

	i = 0;
	while (i < nbr_players)
	{
		std::cout << "Player " << i + 1 << " - Write your first name : ";
		std::cin >> bufName;
		std::cout << "Your email address : ";
		std::cin >> bufMail;
		std::cout << std::endl;
		players[i] = new ClassName(bufName, bufMail, i + 1);
		i++;
	}

	std::srand(time(NULL));
	nbr_gift = 0;
	while (nbr_gift < nbr_players)
	{
		i = 0;
		random = rand() % nbr_players;
		while (i < nbr_players)
		{
			if (players[i]->getGiftTo() == random)
				break ;
			i++;
		}
		if (i == nbr_players)
		{
			if (players[nbr_gift]->getNbr() != random + 1 && players[random]->getGiftTo() != nbr_gift)
			{
				players[nbr_gift]->setGiftTo(random);
				nbr_gift++;
			}
		}

	}

	std::ofstream	mailFile;
	std::ofstream	contentFile;
	std::string		fileName;
	char			newFilename[1024];

	i = 0;
	while (i < nbr_players)
	{
		fileName = players[i]->getName() + "Mail";
		fileName.copy(newFilename, fileName.size() + 1);
		newFilename[fileName.size()] = '\0';
		mailFile.open(newFilename);
		if (mailFile.is_open())
		{
			fileName = players[i]->getName() + "Content";
			fileName.copy(newFilename, fileName.size() + 1);
			newFilename[fileName.size()] = '\0';
			contentFile.open(newFilename);
			if (contentFile.is_open())
			{
				contentFile << "Salut " << players[i]->getName() << "," << std::endl;
				contentFile << std::endl;
				contentFile << "Tu dois offrir ton cadeau a " << players[players[i]->getGiftTo()]->getName() << " !" << std::endl;
				contentFile << std::endl;
				mailFile << players[i]->getMail();
				contentFile.close();
			}
			mailFile.close();
		}
		i++;
	}


	std::ofstream	allEmailsFile;
	std::ofstream	allNamesFile;

	fileName = "allEmails";
	fileName.copy(newFilename, fileName.size() + 1);
	newFilename[fileName.size()] = '\0';
	allEmailsFile.open(newFilename);
	if (allEmailsFile.is_open())
	{
		i = 0;
		fileName = "allNames";
		fileName.copy(newFilename, fileName.size() + 1);
		newFilename[fileName.size()] = '\0';
		allNamesFile.open(newFilename);
		if (allNamesFile.is_open()) {
			while (i < nbr_players)
			{
				allEmailsFile << players[i]->getMail() << std::endl;
				allNamesFile << players[i]->getName() << std::endl;
				delete players[i];
				i++;
			}
			allNamesFile.close();
		}
		allEmailsFile.close();
	}
	return 0;
}