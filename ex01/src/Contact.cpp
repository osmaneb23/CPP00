/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 01:20:21 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/27 19:01:39 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void) : _index(0)
{
}

Contact::~Contact(void)
{
}

std::string Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contact::getNickName(void) const
{
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}

int Contact::getIndex(void) const
{
	return (this->_index);
}

void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void Contact::setIndex(unsigned int index)
{
	this->_index = index;
}

// Display methods
void Contact::displayShort(void) const
{
	std::cout << "|" << std::setw(10) << this->_index;
	std::cout << "|" << std::setw(10) << truncateString(this->_firstName);
	std::cout << "|" << std::setw(10) << truncateString(this->_lastName);
	std::cout << "|" << std::setw(10) << truncateString(this->_nickName);
	std::cout << "|" << std::endl;
}

void Contact::displayFull(void) const
{
	std::cout << "\n────────────── CONTACT DETAILS ──────────────" << std::endl;
	std::cout << "Index          : " << this->_index << std::endl;
	std::cout << "First name     : " << this->_firstName << std::endl;
	std::cout << "Last name      : " << this->_lastName << std::endl;
	std::cout << "Nickname       : " << this->_nickName << std::endl;
	std::cout << "Phone number   : " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->_darkestSecret << std::endl << std::endl;
}

std::string Contact::truncateString(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}