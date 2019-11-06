#include "../ft_printf.h"

int		index_of(char c, const char *str) //returns the index of the first occurence of the specified character in the string 
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*take_out(char *flgs, char f)  //create a new string without any occurence of the specified character
{
	int i;
	char *p;
	i = 0;
	p = flgs;
	while(*p)
	{
		if(*p != f)
			i++;
		p++;
	}
	if (i == ft_strlen(flgs))
		return (flgs);
	p = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while(*flgs)
	{
		if(*flgs != f)
		{
			p[i] = *flgs;
			i++;
		}
		flgs++;
	}
	p[i] = '\0';
	free(flgs);
	return (p);
}