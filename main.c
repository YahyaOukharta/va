#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *s;

	ft_printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%\n", 7,5, "ABC",15,0); //fix precision for hex values
	printf("TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3%", 7,5, "ABC",15,0);
}