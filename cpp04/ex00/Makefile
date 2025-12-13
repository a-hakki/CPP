NAME := a.out
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS := Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean