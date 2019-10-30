#include <stdarg.h>
#include <stdio.h>


void	ft_printf(char *str, ...)
{
	va_list		args;
	
	va_start(args, str);
	while(*str)
	{
		if (*str == 's')
			printf("%s",va_arg(args, char *));
		else if (*str == 'c')
			printf("%c",va_arg(args, int));
		else if (*str == 'd')
			printf("%d",va_arg(args, int));
		else
			printf("%c",*str);

		str++;
	}
	va_end(args);
}

char *get_conversion(char *s, const char *conversions)
{
	int i;
	while ()
}

int main()
{
//	ft_printf("num = d ,  <s> , 's'  ,, c ,, d", 12,"heloodfkjx", "hello world!", '\n',12);
	printf("\n%%",123);
	
}
