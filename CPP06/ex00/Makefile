NAME = converter

SRC =	main.cpp \
		ScalarConverter.cpp

OBJ = $(patsubst %.cpp, %.o, $(SRC))

HEADER = ${shell echo *.hpp}

CC =  g++

FLAGS = -Werror -Wextra -Wall -std=c++98 -pedantic #-Wshadow -Wno-shadow

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ)  -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re