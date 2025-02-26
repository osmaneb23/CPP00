/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:28:17 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/26 03:47:12 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

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
    
  public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(void);
    void searchContact(void) const;
    void displayContacts(void) const;
};

#endif