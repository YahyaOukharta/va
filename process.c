/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkhart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:08:02 by youkhart          #+#    #+#             */
/*   Updated: 2019/11/07 15:08:10 by youkhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_min_width(char *min_width, char **flags, va_list args)
{
	char	*tmp;

	if (min_width && !ft_strncmp(min_width, "*", ft_strlen(min_width)))
	{
		min_width = get_star_param(args, min_width);
		if (ft_atoi(min_width) < 0)
		{
			min_width = ft_substr(min_width, 1, ft_strlen(min_width) - 1);
			tmp = ft_strdup("-");
			*flags = tmp;
		}
	}
	return (min_width);
}

char	*process_arg(char *c, va_list args, const char *t_cs, const char *f)
{
	char *res;
	char t_conv;
	char *flags;
	char *min_width;
	char *precision;

	t_conv = c[strlen(c) - 1];
	flags = get_flags(c, f);
	precision = get_precision(c, t_cs);
	min_width = get_min_width(c, f);
	min_width = process_min_width(min_width, &flags, args);
	if (precision && !ft_strncmp(precision, "*", ft_strlen(precision)))
		precision = get_star_param(args, precision);
	res = get_arg_value(args, t_conv, t_cs);
	if (precision)
		res = add_precision(res, t_conv, precision, t_cs);
	if (precision && flags && t_conv != 's')
		flags = take_out(flags, '0');
	res = add_padding(res, t_conv, min_width, flags);
	free_specifiers(flags, min_width, precision);
	return (res);
}