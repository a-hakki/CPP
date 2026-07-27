NAME := RPN
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp PmergeMe.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS :=	PmergeMe.hpp
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
	
.PHONY: all clean fclean re
