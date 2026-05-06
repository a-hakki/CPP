NAME := a.out
CC := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
SRCS := main.cpp
OBJS := $(SRCS:.cpp=.o)
HEADERS :=	iter.hpp
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
