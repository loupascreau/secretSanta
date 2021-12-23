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

	std::srand(std::time(NULL));
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
		if (i == nbr_players && players[random]->getGiftTo() != nbr_gift && players[nbr_gift]->getNbr() != random)
		{
			players[nbr_gift]->setGiftTo(random);
			nbr_gift++;
		}
	}

	i = 0;
	while (i < nbr_players)
	{
		std::cout << "players " << i << " offer to " << players[i]->getGiftTo() << std::endl;
		delete players[i];
		i++;
	}
	return 0;
}