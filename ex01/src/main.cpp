/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 03:00:35 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/26 03:38:58 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    while (command != "EXIT")
    {
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (std::cin.eof() || std::cin.fail()) 
        {
            std::cout << "\nGoodbye!" << std::endl;
            break;
        }
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            std::cout << "Goodbye!" << std::endl;
        else
            std::cout << "Invalid command. Available commands: ADD, SEARCH, EXIT" << std::endl;
    }
    return (0);
}
