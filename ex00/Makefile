# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 03:38:04 by obouayed          #+#    #+#              #
#    Updated: 2025/02/26 22:46:32 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# Color definitions
RESET = \033[0m
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
ORANGE = \033[38;5;208m
MAGENTA = \033[0;35m
BOLD = \033[1m

NAME = megaphone

SRCDIR = src
OBJDIR = obj
SRCS = $(SRCDIR)/megaphone.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)🚀 Compiling Megaphone Project...$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ Compilation successful!$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@echo "$(BLUE)🎯 Compiling $<...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(PURPLE)🗑️  Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	@echo "$(RED)$(BOLD)🔍 Running Valgrind memory check...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re valgrind