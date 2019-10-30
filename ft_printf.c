/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkhart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:27:49 by youkhart          #+#    #+#             */
/*   Updated: 2019/10/30 07:25:07 by youkhart         ###   ########.fr       */
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
		s = ft_memchr(conv,flgs[ft_strlen(flgs) - 1], ft_strlen(conv)) + 1;
	else 
		s = conv;
	while (ft_isdigit(s[i]) && s[i] != '.' && !ft_memchr(t_convs,s[i],ft_strlen(t_convs)))
		i++;
	printf("i = %d\n",i);
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
	if (i == 0 || !ft_memchr(t_convs, *s, ft_strlen(t_convs)))
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

char	*process_type_spec(char *conv, va_list args) // type specifier
{
	char *res;
	char c;
	
	char *flags;
	char *min_width;
	char *precision;
	
	c = conv[strlen(conv) - 1];
	
	flags = get_flags(conv, "0-");
	precision = get_precision(conv, "cspdiuxX");
	min_width = get_min_width(conv, "0-", "cspdiuxX");

	if (flags)
		printf("\nflags = %s\n", flags);
	if (precision)
		printf("precision = %s\n", precision);
	if (min_width)
		printf("min-width = %s\n", min_width);

	if (c == 'c')
	{
		res = ft_calloc(2 ,1);
		res[0] = va_arg(args, int);
	}
	else if (c == 'd' || c == 'i')
	{
		res = ft_itoa(va_arg(args, int));
	}
	else if (c == 'p' || c == 'x' || c == 'X')
	{
		res = ft_itoa_base(va_arg(args, int),"0123456789abcdef");
		res = ft_strjoin("0x",res);
		if (c == 'X')
		{
			res = ft_strmapi(res, toupper_mapi);
		}
	}
	else if (c == 's')
	{
		res = va_arg(args, char *);
	}
	else if (c == '%')
		return(conv);
	return (res);
}

int	ft_printf(const char *format, ...)
{	
	char *conv;
	char *str;
	va_list		args;

	va_start(args, format);

	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			conv = get_conv(str , "cspdiuxX");
			if (conv)
			{
				ft_putstr_fd(process_type_spec(conv, args), 1);
				str += ft_strlen(conv) + 1;	
			}
			else
				str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			str++;
		}
	}
	return (1);
}
int main(int argc, char **argv)
{
	char *s;
	
	ft_printf("hello <%1212.123s>\n","yahy");
}
