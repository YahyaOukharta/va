NAME = libftprintf.a

all: $(NAME)

$(NAME):
	make re -C libft/
	mv libft/libft.a .
	ar -x libft.a
	gcc -c ft_printf.c ft_itoa_base.c
	ar -rc libftprintf.a *.o 

clean:
	rm -f *.o
	
fclean: clean
	rm -f $(NAME)
re: fclean all
