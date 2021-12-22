/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:22:39 by lpascrea          #+#    #+#             */
/*   Updated: 2021/12/22 17:26:09 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassName.hpp"

int		main(void)
{
	std::string	bufName;
	std::string	bufMail;
	int			i;
	int			nbr_players;
	
	std::cout << std::endl;
	std::cout << MAGEN << "[ Welcome to Secret Santa ] " << WHITE << std::endl;
	std::cout << std::endl;
	
	std::cout << "How many players are you ? ";
	std::cin >> i;

	nbr_players = i;
	std::cout << std::endl;
	std::cout << YELLOW<< "[ You are " << i << " players ] " << WHITE << std::endl;
	std::cout << std::endl;

	ClassName	*players[i];

	i = 0;
	while (i < nbr_players)
	{
		std::cout << "Player " << i + 1 << " Write your first name : ";
		std::cin >> bufName;
		std::cout << "Your email address : ";
		std::cin >> bufMail;
		std::cout << std::endl;
		players[i] = new ClassName(bufName, bufMail, i + 1);
		i++;
	}
	i = 0;
	while (i < nbr_players)
	{
		delete players[i];
		i++;
	}
	return 0;
}