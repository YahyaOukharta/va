#include "ft_printf.h"

int main(void)
{
	ft_printf("<%010.%%d>\n",123);
	printf("<%010.%%d>\n",123);
    return(0);
}