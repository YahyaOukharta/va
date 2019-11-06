#include "ft_printf.h"

int main(int argc, char **argv)
{
	char *s;

	ft_printf(" %*.*d %*.*x %*.*u %*.*p %*.*s\n\n",10,16,1234,10,16, 1234567898,10,16,1245, 10,16,(void *)-1245,10,16, "12346"); //fiX precision for hex values
	   printf(" %*.*d %*.*x %*.*u %*.*p %*.*s\n\n",10,16,1234 ,10,16, 1234567898,10,16,1245, 10,16,(void*)-1245, 10,16,"12346");
	//ft_printf(" %12.p %12.p %12.p %12.p \n\n",(void*)1234, (void*)1234567898 ,(void *)-1245, (void*)12346); //fiX precision for hex values
	 //  printf(" %12.p %12.p %12.p %12.p ",(void*)1234 , (void*)1234567898,(void*)-1245, (void*)12346);
}