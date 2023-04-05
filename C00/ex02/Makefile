NAME = restore
SRC_DIR = src
OBJ_DIR = obj
SRC = $(SRC_DIR)/tests.cpp $(SRC_DIR)/Account.cpp
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
GPP = g++
RM = rm -f
COLOR = \033[36m
RESET = \033[0m

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(GPP) $(FLAGS) $(OBJ) -o $(NAME)
	echo "$(COLOR)$(NAME) created.$(RESET)"
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(GPP) $(FLAGS) -c $< -o $@
$(OBJ_DIR):
	mkdir $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) $(OBJ_DIR)/%.o
	$(RM) -r $(OBJ_DIR)
re: fclean all
.PHONY: all clean fclean re