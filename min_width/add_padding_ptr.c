#include "min_width.h"

char *add_padding_ptr(char *arg, char *width, const char *flags)
{
    char *res;
    char    flag;
    int w;

	if (!width)
		return (ft_strjoin("0x",arg));
    flag = get_active_flag(flags);
    if (flag == '0')
	{
		w = ft_atoi(width);
		w = (w >= 2 ? w - 2 : 0);
		width = ft_itoa(w);
		res = ft_strjoin("0x",add_padding_hex(arg, width, flags));
    }
    else
		res = add_padding_hex(ft_strjoin("0x", arg), width, flags);
	free(arg);
	return (res);
}