/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassName.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpascrea <lpascrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:49:13 by lpascrea          #+#    #+#             */
/*   Updated: 2021/12/23 15:12:50 by lpascrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP

# include <iostream>
# include <cstdlib>
# include <time.h>

# define	MAGEN	"\033[0;35m"
# define	WHITE	"\033[0m"
# define	YELLOW	"\033[0;33m"
# define	GREEN	"\033[0;32m"

class ClassName
{
	public :

	ClassName();
	ClassName(std::string name, std::string mail, int nbr);
	ClassName(ClassName const &obj);
	~ClassName();

	ClassName &	operator=(ClassName const &obj);

	std::string	getName(void) const;
	std::string	getMail(void) const;
	int			getNbr(void) const;
	
	int			getGiftTo(void) const;
	void		setGiftTo(int giftTo);

	private :

	std::string	_name;
	std::string	_mail;
	int			_nbr;
	int			_giftTo;
};

#endif