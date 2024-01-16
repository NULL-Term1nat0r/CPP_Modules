NAME		:= human

SRCS		:= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS		:= $(SRCS:.cpp=.o)

CFLAGS		:= -Wall -Werror -Wextra -std=c++98 -fsanitize=address

CC			:= g++

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean all re fclean

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

all: $(NAME)
