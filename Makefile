CC = clang

CFLAGS = -Wall -Wextra -g3 #-Werror

SRCS = main.c \
		luminous.c

OBJS = $(SRCS:.cpp=.o)

HEADERS = lumonius_rgb.h

NAME = a.out

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re