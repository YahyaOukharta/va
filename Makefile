NAME = libftprintf.a

all: $(NAME)

$(NAME):
	ar -x libft.a
	gcc -c ft_printf.c get_specifiers/*.c type_convs/*.c precision/*.c min_width/*.c # -L. -lft
	ar -rc libftprintf.a *.o 

clean:
	rm -f *.o
	
fclean: clean
	rm -f $(NAME)
re: fclean all

c: re
	gcc main.c -L. -lftprintf
	rm -f *.o
	./a.out

