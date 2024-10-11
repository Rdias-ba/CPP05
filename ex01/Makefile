
NAME = Forms
CPP = c++
FLAGS = -Wextra -Werror -Wall -std=c++98
VPATH = srcs/
Includes = headers/
OBJS_DIR = objs/

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
		$(CPP) $(FLAGS) $(OBJS) -o $@

$(OBJS_DIR):
		mkdir -p $@

$(OBJS_DIR)%.o: %.cpp
		$(CPP) $(FLAGS) -I $(Includes) -c $< -o $@

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re run
