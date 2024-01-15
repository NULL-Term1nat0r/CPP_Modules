NAME = ford

SRC = 	src/PMergeMeList.cpp \
		src/PMergeMeDeque.cpp \
      	src/Parsing.cpp \
		src/main.cpp \



OBJ = $(patsubst %.cpp, %.o, $(SRC))

HEADERS = 	includes/PMergeMe.hpp \
			includes/Parsing.hpp \
			includes/Colors.hpp \

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