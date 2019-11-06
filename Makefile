NAME = libftprintf.a

all: $(NAME)

build_libft:
	make -C libft/ re
	cp libft/libft.a .

$(NAME): build_libft
	ar -x libft.a
	gcc -c ft_printf.c processing/process.c  get_specifiers/*.c type_convs/*.c precision/*.c min_width/*.c  utils/*.c # -L. -lft
	ar -rc libftprintf.a *.o

clean:
	rm -f *.o

	
fclean: clean
	rm -f $(NAME)

re: fclean all

c: re
	gcc main.c -L. -lftprintf -g
	rm -f *.o
	./a.out

