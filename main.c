/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkhart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:17:55 by youkhart          #+#    #+#             */
/*   Updated: 2019/11/10 20:19:23 by youkhart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	ft_printf("<%*.*c>\n",-10,-7,'\0');
	printf("<%*.*c>\n",-10,-7,'\0');
}
