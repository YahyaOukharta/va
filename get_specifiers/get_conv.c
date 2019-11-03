#include "get_specifiers.h"

char *get_conv(char *start, const char *t_convs)
{	
	int len;
	char *p;
	char *conv;
	p = start + 1;
	len = 0;
	while (*p && *p != '%' && !ft_isalpha(*p))
	{
		len++;
		p++;
	}
	if(*p == '%')
		return (ft_strdup("%"));
	if (!ft_memchr(t_convs, *p, ft_strlen(t_convs)))
		return (0);
	else
	{
		len++;
		conv = (char *)malloc(len + 1);
		ft_memcpy(conv, start + 1, len);
		conv[len] = '\0';
		return (conv);
	}
}