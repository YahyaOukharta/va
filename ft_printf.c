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

#include "libft.h"
#include <stdarg.h>

char *get_flags(char *conv, const char *flags) // flags
{
	int i;
	char *s;
	char *res;

	s = conv;
	i = 0;
	while(ft_memchr(flags, *s, ft_strlen(flags)))
	{
		s++;
		i++;
	}
	if (i > 0)
	{
		res = (char *)malloc(i + 1);
		ft_memcpy(res, conv, i);
		res[i] = '\0';
	}
	else
		res = 0;
	return (res);
}

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
	while (ft_isdigit(s[i]))
		i++;
	if (i > 0)
	{
		res = (char *)malloc(sizeof(char) * (i + 1));
		ft_memcpy(res, s, i);
		res[i] = '\0';
		return (res);
	}
	return (0);
}

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
	while (ft_isdigit(*s))
	{
		i++;
		s++;
	}
	if (!ft_memchr(t_convs, *s, ft_strlen(t_convs)))
		return (0);
	res = malloc(sizeof(char) * (i + 1));
	ft_memcpy(res, dot + 1, i);
	res[i] = '\0';
	return (res);
}

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
		return (strdup("%"));
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

int		index_of(char c, char *str)
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

char *get_arg_value(char t_conv, va_list args)
{
	char *res;

	if (t_conv == 'c')
	{
		res = ft_calloc(2 ,1);
		res[0] = va_arg(args, int);
	}
	else if (t_conv == 'd' || t_conv == 'i')
	{
		res = ft_itoa(va_arg(args, int));
	}
	else if (t_conv == 'p' || t_conv == 'x' || t_conv == 'X')
	{
		res = ft_itoa_base(va_arg(args, int),"012345789abcdef"); // negative case
		if(t_conv == 'p')
			res = ft_strjoin("0x",res);
		if(t_conv == 'X')
			res = ft_strmapi(res, toupper_mapi);
	}
	else if (t_conv == 's')
	{
		res = va_arg(args, char *);
		if (!res)
			return (ft_strdup("(null)"));
	}
	else if (t_conv == '%')
		return(ft_strdup("%"));
	return(res);
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

char	*add_precision(char *arg, char t_conv, char *precision) // precision goes first
{
	size_t	p;	//atoi(p)
	size_t	v_len;   //value length
	char 	*res;		
	int size;

	if (!precision || t_conv == 'c')
		return (arg);
	p = ft_atoi(precision);
	if (!p && t_conv == 's')
		return (ft_strdup(""));
	v_len = ft_strlen(arg);
	if (t_conv == 's')
	{
		size = (p < v_len ? p : v_len);
		res = (char *)malloc(sizeof(char) * size + 1); 
		ft_memcpy(res, arg, size);
		res[size] = '\0';
	}
	else
	{
		return (add_padding(arg, t_conv, precision, "0"));
	}
	return (res);
}

char* take_out(char *flgs, char f)  //create a new string without any occurence of the specified character
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

char	*process_arg_value(char *conv, va_list args) 
{
	char *res;
	char t_conv;
	
	char *flags;
	char *min_width;
	char *precision;
	
	t_conv = conv[strlen(conv) - 1]; //type specifier
	
	flags = get_flags(conv, "0-"); //flags 
	precision = get_precision(conv, "cspdiuxX"); //precision
	min_width = get_min_width(conv, "0-", "cspdiuxX"); //min_width

/*	if (flags)
		printf("\nflags = %s\n", flags);

	if (precision)
		printf("precision = %s\n", precision);

	if (min_width)
		printf("min-width = %s\n", min_width);
*/
	res = get_arg_value(t_conv, args);
	//printf("%s\n",res);
	//printf("added precision <%s>\n", add_precision(res, t_conv, precision));
	//printf("added padding <%s>\n", add_padding(res, t_conv, min_width, flags));
	
	if (precision)
		res = add_precision(res, t_conv, precision);
	if (min_width)
	{	
		if (precision && flags && t_conv != 's')
		{
			flags = take_out(flags,'0');
		}
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

	va_start(args, format);
	i = 0;
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			conv = get_conv(str , "cspdiuxX");
			t_conv = conv[ft_strlen(conv) - 1];
			if (conv)
			{
				out = process_arg_value(conv, args);
				ft_putstr_fd(out, 1);		//get_arg_value(t_conv, args), 1);
				str += ft_strlen(conv) + 1;
				i += ft_strlen(out);
			}
			else
			{
				//i++;
				str++;
			}
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

	ft_printf("<%p>\n\n",1567);
	printf("<%p>\n",1567);
}