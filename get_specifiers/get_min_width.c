#include "get_specifiers.h"

char *get_min_width(char *conv, const char *flags, const char *t_convs)
{
	char *res;
	int i;
	char *flgs;
	char *s;
	
	flgs = get_flags(conv,flags);
	if (flgs)
		s = ft_strnstr(conv, flgs, ft_strlen(conv)) + ft_strlen(flgs);
	else 
		s = conv;
	i = 0;
	while (ft_isdigit(s[i]) || s[i] == '*')
		i++;

	if ((res = ft_memchr(s, '*', i)) && i != 1)
		return (0);
	if (i > 0)
	{
		res = (char *)malloc(sizeof(char) * (i + 1));
		ft_memcpy(res, s, i);
		res[i] = '\0';
		return (res);
	}
	return (0);
}