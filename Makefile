NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -c ft_printf.c ft_itoa_base.c 
	ar -x libft.a
	ar rc $(NAME) *.o
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
re: fclean all
