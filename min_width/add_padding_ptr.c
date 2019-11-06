#include "min_width.h"

char *add_padding_ptr(char *arg, char *width, const char *flags)
{
    char *res;
	char *tmp;
    char    flag;
    int w;

	if (!width){
		tmp = ft_strjoin("0x",arg);
		return (tmp);
	}
    flag = get_active_flag(flags);
    if (flag == '0')
	{
		w = ft_atoi(width);
		w = (w >= 2 ? w - 2 : 0);
		width = ft_itoa(w);
		tmp = add_padding_hex(arg, width, flags);
		res = ft_strjoin("0x", tmp);
		//free(tmp);
    }
    else
	{
		tmp = ft_strjoin("0x", arg);
		res = add_padding_hex(tmp, width, flags);
	}
	free(arg);
	return (res);
}