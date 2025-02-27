/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 03:37:04 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/27 19:04:19 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

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

# include <iostream> // Std::cout, Std::cin
# include <iomanip> // Setw

class Contact
{
  private:
    int _index;
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

  public:
    Contact(void);
    ~Contact(void);

    // Getters
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;
    int         getIndex(void) const;

    // Setters
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickName(std::string nickName);
    void setPhoneNumber(std::string phoneNumber);
    void setDarkestSecret(std::string darkestSecret);
    void setIndex(unsigned int index);

    // Display methods
    void displayShort(void) const;
    void displayFull(void) const;

    // Utility methods
    std::string truncateString(std::string str) const;
};

#endif