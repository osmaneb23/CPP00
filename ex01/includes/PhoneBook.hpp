/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:28:17 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/27 04:32:31 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <cstdlib> // Atoi
#include <limits> // std::numeric_limits

# include "Contact.hpp"

class PhoneBook
{
  private:
    static const int _maxcontacts = 8;
    Contact _contacts[_maxcontacts];
    int _count;
    int _oldestIndex;

    void displayPhoneBookHeader(void) const;
    std::string getInput(std::string prompt) const;
    // We are passing a reference of the number (&), better optimisation
    bool isValidPhoneNumber(const std::string &number) const;
    
  public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(void);
    void searchContact(void) const;
    void displayContacts(void) const;
};

#endif