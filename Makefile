CC = cc

CFLAGS = -Wall -Wextra #-Werror
LIB = -lXext -lX11 -lm -lz

SRCS = main.c \
		luminous.c \
		init.c

OBJS = $(SRCS:.c=.o)

HEADERS = lumonius.h \
			init.h

NAME = a.out

all : $(NAME)

$(NAME) : $(OBJS)
	make -C minilibx-linux/
	$(CC) $(CFLAGS) $(OBJS) minilibx-linux/libmlx_Linux.a $(LIB) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re