#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include "libft.h"
#include <stdarg.h>
#include "type_convs/t_convs.h"
#include "get_specifiers/get_specifiers.h"
#include "precision/precision.h"
#include "min_width/min_width.h"
#include <stdio.h>

# define T_CONVS "cspdiuxX%"
int ft_printf(const char *format, ...);
void	ft_swap(char *a, char *b);
#endif