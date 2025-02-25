/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:28:17 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/25 03:11:42 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
  private:
	static const int _maxcontacts = 8;
	Contact _contacts[_maxcontacts];
	

  public:
	PhoneBook(void);
	~PhoneBook(void);

	char *contacts;
};

#endif