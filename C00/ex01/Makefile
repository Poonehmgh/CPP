NAME = Phonebook
SRC_DIR = src
SRC		= $(SRC_DIR)/phonebook.cpp $(SRC_DIR)/contact.cpp $(SRC_DIR)/main.cpp
INCLUDE = inc
OBJ = $(SRC:.cpp=.o)
FLAGS	= -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address
CPP		= c++
RM		= rm -f
COLOR	= \033[36m
RESET = \033[0m

all: $(NAME)

$(NAME):
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)
	echo "$(COLOR)$(NAME) created.$(RESET)"

fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) $(SRC_DIR)/$(OBJ)
re: fclean all
.PHONY: all re clean fclean