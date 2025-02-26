/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:19:58 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/26 03:47:08 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <cstdlib> // For atoi
#include <limits>

PhoneBook::PhoneBook(void) : _count(0), _oldestIndex(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::addContact(void)
{
	Contact	newContact;

	std::string input;
	do
	{
		input = getInput("Enter first name: ");
	} while (input.empty());
	newContact.setFirstName(input);
	do
	{
		input = getInput("Enter last name: ");
	} while (input.empty());
	newContact.setLastName(input);
	do
	{
		input = getInput("Enter nickname: ");
	} while (input.empty());
	newContact.setNickName(input);
	do
	{
		input = getInput("Enter phone number: ");
	} while (input.empty());
	newContact.setPhoneNumber(input);
	do
	{
		input = getInput("Enter darkest secret: ");
	} while (input.empty());
	newContact.setDarkestSecret(input);
	// Set contact index and add to phonebook
	if (_count < _maxcontacts)
	{
		newContact.setIndex(_count);
		_contacts[_count] = newContact;
		_count++;
	}
	else
	{
		newContact.setIndex(_oldestIndex);
		_contacts[_oldestIndex] = newContact;
		_oldestIndex = (_oldestIndex + 1) % _maxcontacts;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact(void) const
{
	if (_count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

	displayContacts();

	std::string indexStr;
	int index;

	indexStr = getInput("Enter the index of the contact to display: ");

	// C++98 compatible string to integer conversion
	// First check if the input is numeric
	bool isNumeric = true;
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
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	// Convert string to integer using atoi (part of C standard library)
	index = atoi(indexStr.c_str());

	// Check if the index is in range
	if (index < 0 || index >= _count)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}

	_contacts[index].displayFull();
}

void PhoneBook::displayContacts(void) const
{
	if (_count == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}

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

std::string PhoneBook::getInput(std::string prompt) const
{
	std::string input;

	std::cout << prompt;
	std::getline(std::cin, input);

	// Check for EOF or error
	if (std::cin.eof() || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ("");
	}

	return (input);
}