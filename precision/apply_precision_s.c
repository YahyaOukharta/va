#include "precision.h"

char	*add_precision_s(char *arg, char *precision)
{
	size_t	p;	//atoi(p)
	size_t	v_len;   //value length
	char 	*res;		
	int size;

	if (!precision)
		return (arg);
	p = ft_atoi(precision);
	if (!p)
		return (ft_strdup(""));
    v_len = ft_strlen(arg);
    size = (p < v_len ? p : v_len);
    res = (char *)malloc(sizeof(char) * size + 1); 
    ft_memcpy(res, arg, size);
    res[size] = '\0';
	free(arg);
	return (res);
}