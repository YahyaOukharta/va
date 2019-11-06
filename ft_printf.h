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

int     ft_printf(const char *format, ...);
void	ft_swap(char *a, char *b);
int		index_of(char c, const char *str);
char	*take_out(char *flgs, char f);

char    *get_star_param(va_list args, char *old_param);
char    *get_arg_value( va_list args, char t_conv, const char* t_convs);
char	*add_padding(char *arg, char t_conv, char *width, const char *flags);
char	*add_precision(char *arg, char t_conv, char *precision, const char *t_convs); // precision goes first
char	*process_arg_value(char *conv, va_list args, const char *t_convs, const char *flgs);

#endif