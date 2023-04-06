NAME = brain
SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp
OBJ = $(SRC:%.cpp=%.o)
FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address
GPP = g++
RM = rm -f
COLOR = \033[36m
RESET = \033[0m

all: $(NAME)

$(NAME) : 
	$(GPP) $(FLAGS) $(SRC) -o $(NAME)
	echo "$(COLOR)$(NAME) created.$(RESET)"
fclean : clean
	$(RM) $(NAME)
clean:
	$(RM) $(OBJ)
re: fclean all
.PHONY: all re clean fclean
