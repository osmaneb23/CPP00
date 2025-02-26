/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 03:00:35 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/26 23:58:58 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: " << GREEN << "ADD" << RESET << ", " 
              << ORANGE << "SEARCH" << RESET << ", " 
              << PURPLE << "EXIT" << RESET << std::endl;
    while (command != "EXIT")
    {
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (std::cin.eof()) 
        {
            std::cout << PURPLE << "EOF detected. Exiting program." << RESET << "\nGoodbye!" << std::endl;
            break;
        }
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            std::cout << "Goodbye!" << std::endl;
        else
            std::cout << RED << "Invalid command." << RESET << " Available commands: " 
                      << GREEN << "ADD" << RESET << ", " 
                      << ORANGE << "SEARCH" << RESET << ", " 
                      << PURPLE << "EXIT" << RESET << std::endl;
    }
    return (0);
}
