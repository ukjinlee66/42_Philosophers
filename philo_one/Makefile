NAME = Philo_one

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/main.c \
		srcs/init.c \
		srcs/parse.c \
		srcs/philo.c \
		srcs/util.c \
		srcs/philo_action.c

INCLUDES = -I ./includes/

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
