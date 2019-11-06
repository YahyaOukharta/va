#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *s;

	ft_printf("ft_printf : <%*.3s>\n",-15,"ABC"); //fix precision for hex values
	printf("printf    : <%*.3s>\n",-15,"ABC");
}