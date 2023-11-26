NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c	\
	  ft_putchar.c	\
	  put_int.c		\
	  ft_put_str.c	\
	  ft_put_hex.c

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):$(OBJ)
		ar rcs $@ $^

%.o : %.c
		cc ${CFLAGS} -o $@ -c $^

clean :
		rm -f $(OBJ) $(OBJBONUS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
