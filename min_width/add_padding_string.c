#include "min_width.h"

char	*add_padding_string(char *arg, char *width, const char *flags)
{
	char flag;
	char *res;
	size_t w;	// atoi(width)
	size_t v_len; //length of arg 

	flag = get_active_flag(flags);
	w = ft_atoi(width);
	v_len = ft_strlen(arg);
	if (w <= v_len)
		return (arg);
	res = (char *)malloc(sizeof(char) * (w + 1)); // needs protection
	if(flag == '-')
	{
		ft_strlcpy(res, arg, w + 1);
		ft_memset(res + v_len, ' ', w - v_len);
	}
	else
	{
		ft_strlcpy(res + (w - v_len), arg, v_len + 1);
		ft_memset(res,' ', w - v_len);
	}
	res[w] = '\0';
	return (res);
}