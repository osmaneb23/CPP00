/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:28:17 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/27 18:26:18 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

// Color definitions
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;5;208m"
#define BOLD    "\033[1m"

# include <iomanip> // Setw
# include <iostream> // Std::cout, Std::cin
# include <cstdlib> // Atoi
# include <cstdio> // clearerr

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
    // We are passing a reference of the number (&) so we don't make a copy of it (optimization)
    bool isValidPhoneNumber(const std::string &number) const;
    
  public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addContact(void);
    void searchContact(void) const;
    void displayContacts(void) const;
};

#endif