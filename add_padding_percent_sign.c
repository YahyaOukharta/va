/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding_percent_sign.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkhart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:17 by youkhart          #+#    #+#             */
/*   Updated: 2019/11/07 13:41:47 by youkhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "min_width.h"

char	*add_padding_percent_sign(char *arg, char *width, const char *flags)
{
	char	*s;

	(void)flags;
	s = add_padding_string(arg, width, flags);
	return (s);
}
