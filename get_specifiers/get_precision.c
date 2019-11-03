#include "get_specifiers.h"

char *get_precision(char *conv, const char *t_convs )
{
	int		i;
	char	*res;
	char	*dot;
	char	*s;

	dot = ft_memchr(conv, '.',ft_strlen(conv));
	if (!dot)
		return (0);
	i = 0;
	s = dot + 1;
	while (ft_isdigit(s[i]) || s[i] == '*')
		i++;
	if ((res = ft_memchr(s, '*', i)) && i != 1)
		return (0);
	if (!ft_memchr(t_convs, s[i], ft_strlen(t_convs)))
		return (0);
	res = malloc(sizeof(char) * (i + 1));
	ft_memcpy(res, s, i);
	res[i] = '\0';
	return (res);
}