NAME := a.out
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean