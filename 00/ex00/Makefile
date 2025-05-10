NAME=megaphone
CC=c++
FLAGS= -std=c++98 -Wall -Wextra -Werror
SRCS = megaphone.cpp

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<

OBJS= $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re