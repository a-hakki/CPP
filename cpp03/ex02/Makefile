NAME := a.out
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS := $(SRCS:.cpp=.o)
HDRS := ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

%.o: %.cpp $(HDRS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean