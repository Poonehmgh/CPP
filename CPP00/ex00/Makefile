NAME = megaphone
SRC = megaphone.cpp
OBJ = ${SRC:.cpp=.o}
HEADER =
FLAGS = -Wall -Werror -Wextra -std=c++98
CPP = c++
RM = rm -f
COLOR = \033[36m
RESET = \033[0m
# %.o:	%.cpp ${HEADER}
# 		${CPP} -c ${FLAGS} -I. $< -o ${<:.cpp=.o}
all: $(NAME)

$(NAME):
	$(CPP) $(FLAGS) $(SRC) -o $(NAME)
	echo "$(COLOR)$(NAME) created.$(RESET)"
fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) $(OBJ)
re: fclean all
.PHONY: all clean fclean re