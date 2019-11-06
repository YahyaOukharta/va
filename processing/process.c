#include "../ft_printf.h"

char*	get_star_param(va_list args)
{
	return (ft_itoa(va_arg(args, int)));
}

char *get_arg_value( va_list args, char t_conv, const char* t_convs)
{
	int index;

	index = index_of(t_conv, t_convs);
	if(index > -1)
		return (t_dispatcher[index](args));
	else
		return (0);
}

char	*add_padding(char *arg, char t_conv, char *width, const char *flags)
{	
	int index;
	char *res;

	index = index_of(t_conv, "cspdiuxX%");
	res = w_dispatcher[index](arg, width, flags);
	return (res);

}

char	*add_precision(char *arg, char t_conv, char *precision, const char *t_convs) // precision goes first
{
	char	*res;		
	int		index;

	if (!precision)
		return (arg);
	index = index_of(t_conv, t_convs);
	res = p_dispatcher[index](arg, precision);
	return (res);
}

char	*process_arg_value(char *conv, va_list args, const char *t_convs, const char *flgs) 
{
	char *res;
	char t_conv;
	
	char *flags;
	char *min_width;
	char *precision;
	
	t_conv = conv[strlen(conv) - 1]; //type specifier
	flags = get_flags(conv, flgs); //flags 
	precision = get_precision(conv, t_convs); //precision
	min_width = get_min_width(conv, flgs, t_convs); //min_width

	if (min_width && !ft_strncmp(min_width, "*", ft_strlen(min_width)))
		min_width = get_star_param(args);
	if (precision && !ft_strncmp(precision, "*", ft_strlen(precision)))
		precision = get_star_param(args);
	res = get_arg_value(args, t_conv, t_convs);
	if (precision)
		res = add_precision(res, t_conv, precision, t_convs);
	if (min_width)
	{	
		if (precision && flags && t_conv != 's')
			flags = take_out(flags,'0');
		res = add_padding(res, t_conv, min_width, flags);
	}
	return (res);

}