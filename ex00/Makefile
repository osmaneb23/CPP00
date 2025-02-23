NAME = megaphone

SRCDIR = src
OBJDIR = obj
SRCS = $(SRCDIR)/megaphone.cpp
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	@echo "🚀 Compiling Megaphone Project..."
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
