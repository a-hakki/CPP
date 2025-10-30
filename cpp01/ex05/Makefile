NAME = complining

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
FLAGS = -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re