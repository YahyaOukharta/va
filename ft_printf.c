/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkhart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:27:49 by youkhart          #+#    #+#             */
/*   Updated: 2019/10/30 23:46:55 by youkhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char*	get_star_param(va_list args)
{
	return (ft_itoa(va_arg(args, int)));
}

int		index_of(char c, const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

char	toupper_mapi(unsigned int i, char c)
{
	return (ft_toupper(c));
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

void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*add_padding(char *arg, char t_conv, char *width, const char *flags)
{
	char flag;
	char *res;
	char *ptr; 
	size_t w;	// atoi(width)
	size_t v_len; // value length

	ptr = (char *)flags;
	flag = 0;
	//get flag
	while (ptr && *ptr)
	{
		if (*ptr == '0')
			flag = '0';
		if(*ptr == '-')
		{
			flag = '-';
			break;
		}
		ptr++;
	}
	w = ft_atoi(width);
	v_len = ft_strlen(arg);
	if (w < v_len)
		return (arg);
	res = (char *)malloc(sizeof(char) * (w + 1)); // needs protection
	if(flag == '-')
	{
		ft_strlcpy(res, arg, w + 1);
		ft_memset(res + v_len, ' ', w - v_len);
	}
	else
	{	
		// must add conditions for each type (negative int, hex 0x, etc ..)
		ft_strlcpy(res + (w - v_len), arg, v_len + 1);
		ft_memset(res,(flag == '0' ? '0' : ' '), w - v_len);
		if (ft_strchr("diu", t_conv) && ft_atoi(arg) < 0)
			ft_swap(res, res + w - v_len);
		else if(ft_strchr("p", t_conv))
			ft_swap(res + 1, res + w - v_len + 1);

	}
	res[w] = '\0';
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
	return (p);
}

char	*process_arg_value(char *conv, va_list args, const char *t_convs) 
{
	char *res;
	char t_conv;
	
	char *flags;
	char *min_width;
	char *precision;
	
	t_conv = conv[strlen(conv) - 1]; //type specifier
	
	flags = get_flags(conv, "0-"); //flags 
	precision = get_precision(conv, t_convs); //precision
	min_width = get_min_width(conv, "0-", t_convs); //min_width

/*	if (flags)
		printf("\nflags = %s\n", flags);

	if (precision)
		printf("precision = %s\n", precision);

	if (min_width)
		printf("min-width = %s\n", min_width);
*/

	if (min_width && !ft_strncmp(min_width, "*", ft_strlen(min_width)))
		min_width = get_star_param(args);
	
	if (precision && !ft_strncmp(precision, "*", ft_strlen(precision)))
		precision = get_star_param(args);

/*	if (precision)
		printf("precision = %s\n", precision);

	if (min_width)
		printf("min-width = %s\n", min_width);
*/
	res = get_arg_value(args, t_conv, t_convs);
	//printf("%s\n",res);
	//printf("added precision <%s>\n", add_precision(res, t_conv, precision));
	//printf("added padding <%s>\n", add_padding(res, t_conv, min_width, flags));
	
	if (precision){
		res = add_precision(res, t_conv, precision, t_convs);
	}
	if (min_width)
	{	
		if (precision && flags && t_conv != 's')
			flags = take_out(flags,'0');
		res = add_padding(res, t_conv, min_width, flags);
	}
	return (res);

}

int	ft_printf(const char *format, ...)
{	
	char *conv;
	char *str;
	char *out;
	char t_conv;
	int i;
	va_list		args;
	init_t_dispatcher();
	init_p_dispatcher();

	va_start(args, format);
	i = 0;
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			conv = get_conv(str , "cspdiuxX%");
			t_conv = conv[ft_strlen(conv) - 1];
			if (conv)
			{
				out = process_arg_value(conv, args, "cspdiuxX%");
				ft_putstr_fd(out, 1);		//get_arg_value(t_conv, args), 1);
				str += ft_strlen(conv) + 1;
				i += ft_strlen(out);
			}
			else
				str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
			str++;
		}
	}
	return (i);
}

int main(int argc, char **argv)
{
	char *s;

	ft_printf("<%-20.*s>\n",5,"Hedfdfdflo World!"); //fix precision for hex values
	//printf("<%-4%//d>\n\n",5,7295);
}