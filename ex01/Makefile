# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 03:11:14 by obouayed          #+#    #+#              #
#    Updated: 2025/02/27 19:06:08 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color definitions
RESET           =   \033[0m
# Regular colors
BLACK           =   \033[0;30m
RED             =   \033[0;31m
GREEN           =   \033[0;32m
YELLOW          =   \033[0;33m
BLUE            =   \033[0;34m
PURPLE          =   \033[0;35m
CYAN            =   \033[0;36m
WHITE           =   \033[0;37m
# Light colors
LIGHT_BLACK     =   \033[0;90m
LIGHT_RED       =   \033[0;91m
LIGHT_GREEN     =   \033[0;92m
LIGHT_YELLOW    =   \033[0;93m
LIGHT_BLUE      =   \033[0;94m
LIGHT_PURPLE    =   \033[0;95m
LIGHT_CYAN      =   \033[0;96m
LIGHT_WHITE     =   \033[0;97m
# Dark colors
DARK_BLACK      =   \033[0;30m
DARK_RED        =   \033[0;31;2m
DARK_GREEN      =   \033[0;32;2m
DARK_YELLOW     =   \033[0;33;2m
DARK_BLUE       =   \033[0;34;2m
DARK_PURPLE     =   \033[0;35;2m
DARK_CYAN       =   \033[0;36;2m
DARK_WHITE      =   \033[0;37;2m
# Bold colors
BOLD_BLACK      =   \033[1;30m
BOLD_RED        =   \033[1;31m
BOLD_GREEN      =   \033[1;32m
BOLD_YELLOW     =   \033[1;33m
BOLD_BLUE       =   \033[1;34m
BOLD_PURPLE     =   \033[1;35m
BOLD_CYAN       =   \033[1;36m
BOLD_WHITE      =   \033[1;37m
# Underline colors
UNDER_BLACK     =   \033[4;30m
UNDER_RED       =   \033[4;31m
UNDER_GREEN     =   \033[4;32m
UNDER_YELLOW    =   \033[4;33m
UNDER_BLUE      =   \033[4;34m
UNDER_PURPLE    =   \033[4;35m
UNDER_CYAN      =   \033[4;36m
UNDER_WHITE     =   \033[4;37m
# Background colors
BG_BLACK        =   \033[40m
BG_RED          =   \033[41m
BG_GREEN        =   \033[42m
BG_YELLOW       =   \033[43m
BG_BLUE         =   \033[44m
BG_PURPLE       =   \033[45m
BG_CYAN         =   \033[46m
BG_WHITE        =   \033[47m
# Special colors
ORANGE          =   \033[38;5;208m
PINK            =   \033[38;5;206m
LIME            =   \033[38;5;118m
TEAL            =   \033[38;5;30m
LAVENDER        =   \033[38;5;141m
BROWN           =   \033[38;5;130m
GOLD            =   \033[38;5;220m
SILVER          =   \033[38;5;7m
# Text styles
BOLD            =   \033[1m
FAINT           =   \033[2m
ITALIC          =   \033[3m
UNDERLINE       =   \033[4m
BLINK           =   \033[5m
REVERSE         =   \033[7m
HIDDEN          =   \033[8m
STRIKETHROUGH   =   \033[9m

# Project name
NAME = phonebook

# Directories
SRCDIR = src
OBJDIR = obj
INCDIR = includes

# Header files
INCLUDES = $(INCDIR)/PhoneBook.hpp \
	$(INCDIR)/Contact.hpp

# Source files
SRCS = $(SRCDIR)/PhoneBook.cpp \
	$(SRCDIR)/Contact.cpp \
	$(SRCDIR)/main.cpp

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# For progress tracking
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE = 0

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@start_time=$$(date +%s.%N); \
	echo "$(TEAL)⚙️  Assembling PhoneBook Project...$(RESET)"; \
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME); \
	end_time=$$(date +%s.%N); \
	elapsed_secs=$$(echo "$$end_time - $$start_time" | bc); \
	total_seconds=$$(echo "$$elapsed_secs / 1" | bc); \
	milliseconds=$$(echo "scale=3; ($$elapsed_secs - $$total_seconds) * 1000 / 1" | bc | awk '{printf "%.0f", $$0}'); \
	minutes=$$(echo "$$total_seconds / 60" | bc); \
	seconds=$$(echo "$$total_seconds % 60" | bc); \
	if [ $$minutes -gt 0 ]; then \
		echo "$(BOLD_GREEN)✅ Compilation successful! $(BOLD_WHITE)[Time: $${minutes}m $${seconds}s $${milliseconds}ms]$(RESET)"; \
	elif [ $$seconds -gt 0 ]; then \
		echo "$(BOLD_GREEN)✅ Compilation successful! $(BOLD_WHITE)[Time: $${seconds}s $${milliseconds}ms]$(RESET)"; \
	else \
		echo "$(BOLD_GREEN)✅ Compilation successful! $(BOLD_WHITE)[Time: $${milliseconds}ms]$(RESET)"; \
	fi

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@printf "$(LIGHT_BLUE)🛠️  Compiling [%d/%d] %s...$(RESET)\n" $(CURRENT_FILE) $(TOTAL_FILES) $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@echo "$(LIGHT_YELLOW)📂 Creating objects directory...$(RESET)"
	@mkdir -p $(OBJDIR)

# Cleaning rules
clean:
	@echo "$(ORANGE)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(LAVENDER)🗑️  Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all
	@echo "$(LIME)♻️  Project rebuilt from scratch!$(RESET)"

# Compile if necessary and run
run: all
	@echo "$(BOLD_CYAN)▶️  Running $(NAME)...$(RESET)"
	@./$(NAME)

# Rebuild from scratch and run
rerun: re
	@echo "$(BOLD_CYAN)🔄 Running $(NAME) after rebuild...$(RESET)"
	@./$(NAME)

# Debug tools
valgrind: $(NAME)
	@echo "$(BOLD_RED)🔍 Running Valgrind memory check...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

# Index
help:
	@echo "$(BOLD_CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)      - Build the program"
	@echo "  $(GREEN)clean$(RESET)    - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)   - Remove object files and executable"
	@echo "  $(GREEN)re$(RESET)       - Rebuild from scratch"
	@echo "  $(GREEN)run$(RESET)      - Compile if needed and run"
	@echo "  $(GREEN)rerun$(RESET)    - Rebuild from scratch and run"
	@echo "  $(GREEN)valgrind$(RESET) - Run with memory leak check"
	@echo "  $(GREEN)help$(RESET)     - Show this help message"

.PHONY: all clean fclean re valgrind help run rerun