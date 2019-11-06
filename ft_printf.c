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
	init_w_dispatcher();

	va_start(args, format);
	i = 0;
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			conv = get_conv(str , "cspdiuxX%");
			if (conv)
			{	
				t_conv = conv[ft_strlen(conv) - 1];
				out = process_arg_value(conv, args, "cspdiuxX%" , "0-");
				ft_putstr_fd(out, 1);		//get_arg_value(t_conv, args), 1);
				str += ft_strlen(conv) + 1;
				i += ft_strlen(out);
				free(conv);
				free(out);
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
	va_end(args);
	return (i);
}
