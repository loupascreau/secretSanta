/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassName.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:50:12 by lpascrea          #+#    #+#             */
/*   Updated: 2021/12/23 15:12:50 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassName.hpp"

ClassName::ClassName() : _name(""), _mail(""), _nbr(0), _giftTo(-1)
{
	std::cout << "Default Constructor ClassName called" << std::endl;
}

ClassName::ClassName(std::string name, std::string mail, int nbr) : _name(name), _mail(mail), _nbr(nbr), _giftTo(-1)
{
	std::cout << GREEN << "[ Player " << this->_nbr << " ] " << WHITE << std::endl;;
	std::cout << "Name : " << this->_name << std::endl;
	std::cout << "Mail : " << this->_mail << std::endl;
	std::cout << std::endl;
}

ClassName::ClassName(ClassName const &obj)
{
	*this = obj;
	return ;
}

ClassName &	ClassName::operator=(ClassName const &obj)
{
	this->_name = obj.getName();
	this->_mail = obj.getMail();
	this->_nbr = obj.getNbr();
	return *this;
}

std::string	ClassName::getName(void) const
{
	return this->_name;
}

std::string	ClassName::getMail(void) const
{
	return this->_mail;
}

int			ClassName::getNbr(void) const
{
	return this->_nbr;
}

int			ClassName::getGiftTo(void) const
{
	return this->_giftTo;
}

void		ClassName::setGiftTo(int giftTo)
{
	this->_giftTo = giftTo;
}

ClassName::~ClassName()
{
	// std::cout << "Destructor ClassName called" << std::endl;
}