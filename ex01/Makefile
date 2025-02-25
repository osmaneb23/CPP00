# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 03:11:14 by obouayed          #+#    #+#              #
#    Updated: 2025/02/25 03:12:32 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCDIR = src
OBJDIR = obj
INCDIR = includes

INCLUDES = $(INCDIR)/PhoneBook.hpp \
		$(INCDIR)/Contact.hpp

SRCS = $(SRCDIR)/PhoneBook.cpp \
		$(SRCDIR)/Contact.cpp \
		$(SRCDIR)/main.cpp

OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@echo "🚀 Compiling PhoneBook Project..."
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ Compilation successful!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@echo "🎯 Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "🧹 Cleaning object files..."
	rm -rf $(OBJDIR)

fclean: clean
	@echo "🗑️  Removing executable..."
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	@echo "🐛 Running Valgrind..."
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re valgrind