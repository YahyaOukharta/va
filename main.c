#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *s;

	ft_printf("ft_printf : <%20p>\n",&s); //fix precision for hex values
	printf("printf    : <%20p>\n",&s);
}