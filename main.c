#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *s;

	ft_printf("ft_printf : <%6.0-10c>\n",'a'); //fix precision for hex values
	printf("printf    : <%6.0-10c>\n", 'a');
}