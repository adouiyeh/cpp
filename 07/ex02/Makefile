NAME = array
CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra 
INCS = $(wildcard *.hpp)
TPPS = $(wildcard *.tpp)
SRCS = $(wildcard *.cpp) 

%.o: %.cpp $(INCS) $(TPPS)
	$(CC) $(FLAGS) -c -o $@ $< 

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re