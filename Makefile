NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c key_event.c image_set.c parse.c gnl.c gnl_utils.c valid.c print.c key_event2.c dfs.c utils.c
INC = so_long.h
OBJS = $(SRCS:.c=.o)
RM = rm
RMFLAGS = -f


all: $(NAME) 

clean:
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I ${INC} -L./mlx -lmlx -framework OpenGL -framework AppKit -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re bonus