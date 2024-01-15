NAME = iter
SRC_DIR = src
OBJ_DIR = objects

SOURCES = src/subjectTest.cpp
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

HEADER_DIR = includes
HEADERS = includes/array.hpp

CC = g++
FLAGS = -g -Wextra -Wall -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re