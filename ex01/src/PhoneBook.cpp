/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:19:58 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/27 04:45:34 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _count(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

std::string PhoneBook::getInput(std::string prompt) const
{
    std::string input;
	
    do
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cin.clear(); // Clear the EOF state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining input (not working)
            return ("");
        }
    } while (input.empty());
    return (input);
}

// Allow only digits, plus (at beginning), dashes, spaces, parentheses, and periods
bool PhoneBook::isValidPhoneNumber(const std::string &number) const
{
	bool hasDigit = false;
	
    if (number.empty())
        return (hasDigit);
    if (number[0] != '+' && !isdigit(number[0]))
        return (hasDigit);
    for (size_t i = 0; i < number.length(); i++)
    {
        char c = number[i];
        if (isdigit(c))
            hasDigit = true;
        else if (c == '+' && i != 0)
            return (false);
        else if (c != '-' && c != ' ' && c != '(' && c != ')' && c != '.' && c != '+')
            return (false);
    }
    return (hasDigit); 
}

void PhoneBook::addContact(void)
{
    Contact newContact;
    std::string input;
    std::string fields[] = 
	{
        "first name",
        "last name",
        "nickname",
        "phone number",
        "darkest secret"
    };
	
    for (int i = 0; i < 5; i++)
    {
        while (true)
        {
            input = getInput("Enter " + fields[i] + ": ");
            if (input.empty())
            {
                std::cout << PURPLE << "Contact addition cancelled." << RESET << std::endl;
                return;
            }
            if (i == 3 && !isValidPhoneNumber(input))
            {
                std::cout << RED << "Invalid phone number.\nOnly digits, plus sign (at beginning), dashes, spaces, parentheses, and periods are allowed." << RESET << std::endl;
                continue;
            }
            break;
        }
        switch (i)
        {
            case 0: newContact.setFirstName(input); break;
            case 1: newContact.setLastName(input); break;
            case 2: newContact.setNickName(input); break;
            case 3: newContact.setPhoneNumber(input); break;
            case 4: newContact.setDarkestSecret(input); break;
        }
    }
    if (_count < _maxcontacts)
    {
        newContact.setIndex(_count);
        this->_contacts[_count] = newContact;
        this->_count++;
    }
    else
    {
        newContact.setIndex(_oldestIndex);
        this->_contacts[_oldestIndex] = newContact;
        this->_oldestIndex = (_oldestIndex + 1) % _maxcontacts;
    }
    std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
}

void PhoneBook::searchContact(void) const
{
	std::string indexStr;
    int index;
	bool isNumeric;
	
    if (this->_count == 0)
    {
        std::cout << RED << "No contacts found. The phonebook is currently empty." << RESET << std::endl;
        return ;
    }
    displayContacts();
	while (true)
	{
		indexStr = getInput("Enter the index of the contact to display: ");
		if (indexStr.empty())
		{
			std::cout << PURPLE << "Contact search cancelled." << RESET << std::endl;
			return;
		}
		isNumeric = true;
		for (size_t i = 0; i < indexStr.length(); i++)
		{
			if (!isdigit(indexStr[i]))
			{
				isNumeric = false;
				break ;
			}
		}
		if (!isNumeric || indexStr.empty())
		{
			std::cout << RED << "Invalid index." << RESET << std::endl;
			continue ;
		}
        // Convert string to const char to pass it to atoi
        index = atoi(indexStr.c_str());
		if (index < 0 || index >= _count)
		{
			std::cout << RED << "Invalid index." << RESET << std::endl;
			continue ;
		}
		break;
	}
    this->_contacts[index].displayFull();
}

void PhoneBook::displayContacts(void) const
{
    displayPhoneBookHeader();
    for (int i = 0; i < _count; i++)
    {
        _contacts[i].displayShort();
    }
}

void PhoneBook::displayPhoneBookHeader(void) const
{
    std::cout << "|" << std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname";
    std::cout << "|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
}
