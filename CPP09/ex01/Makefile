NAME = RPN

SRC = src/main.cpp \

OBJ = $(patsubst %.cpp, %.o, $(SRC))

HEADERS = $(wildcard $(HEADER_DIR)/*.hpp)

CC =  c++

FLAGS = -Werror -Wextra -Wall -std=c++98 -pedantic

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ)  -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re