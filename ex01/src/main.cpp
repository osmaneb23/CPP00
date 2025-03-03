/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 03:00:35 by obouayed          #+#    #+#             */
/*   Updated: 2025/02/27 18:27:36 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void displayWelcomeMessage(void)
{
    std::cout << CYAN << "\n" <<
        "  ____  _                      ____              _    \n" <<
        " |  _ \\| |__   ___  _ __   ___| __ )  ___   ___ | | __\n" <<
        " | |_) | '_ \\ / _ \\| '_ \\ / _ \\  _ \\ / _ \\ / _ \\| |/ /\n" <<
        " |  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   < \n" <<
        " |_|   |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\\n" <<
        "                                                      \n" << RESET;
    std::cout << YELLOW << "★★★ " << RESET << "Welcome to the 80's PhoneBook Manager" << YELLOW << " ★★★" << RESET << std::endl;
    std::cout << "Never lose a contact again!" << std::endl << std::endl;
}

int main(void)
{
    PhoneBook phoneBook;
    std::string command;
    const std::string availableCommands = "Available commands: " 
              + std::string(GREEN) + "ADD" + std::string(RESET) + ", " 
              + std::string(ORANGE) + "SEARCH" + std::string(RESET) + ", " 
              + std::string(PURPLE) + "EXIT" + std::string(RESET);
    const std::string goodbyeMessage = BOLD + std::string("\nEnd of the line. Catch you on the flip side!") + RESET;

    displayWelcomeMessage();
    std::cout << availableCommands << std::endl;
    
    while (true)
    {
        std::cout << ">> ";
        if (!std::getline(std::cin, command))
        {
            std::cout << PURPLE << "Exiting program.\n" << RESET << goodbyeMessage << std::endl;
            break;
        }
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
        {
            std::cout << goodbyeMessage << std::endl;
            break;
        }
        else
            std::cout << RED << "Invalid command." << RESET << " " << availableCommands << std::endl;
    }
    return (0);
}
