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

void	init_ft_printf(char **str, int *i, const char *format)
{
	init_t_dispatcher();
	init_p_dispatcher();
	init_w_dispatcher();
	*i = 0;
	*str = (char *)format;
}

void	print_null_before(char **tab, int *i)
{
	if (!*tab[1] && get_active_flag(tab[2]) == '-')
	{
		i++;
		ft_putchar_fd('\0', 1);
	}
}

void	print_null_after(char **tab, int *i)
{
	if (!*tab[1] && get_active_flag(tab[2]) != '-')
	{
		i++;
		ft_putchar_fd('\0', 1);
	}
}

void	print_output(char **out, int *i)
{
	print_null_before(out, i);
	ft_putstr_fd(out[0], 1);
	print_null_after(out, i);
}

int		ft_printf(const char *format, ...)
{
	char	*conv;
	char	*str;
	char	**out;
	int		i;
	va_list	args;

	va_start(args, format);
	init_ft_printf(&str, &i, format);
	while (*str)
		if (*str == '%' && (conv = get_conv(str, "cspdiuxX%")))
		{
			out = process_arg(conv, args, "cspdiuxX%", "0-");
			print_output(out, &i);
			str += ft_strlen(conv) + 1;
			i += ft_strlen(out[0]);
			free_specifiers(NULL, conv, NULL, out);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			i++;
			str++;
		}
	va_end(args);
	return (i);
}
