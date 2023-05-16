CC = cc

CFLAGS = -Wall -Wextra #-Werror

SRCS = main.c \
		luminous.c

OBJS = $(SRCS:.c=.o)

HEADERS = lumonius.h

NAME = a.out

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re