#ifndef GET_SPECIFIERS_H
# define GET_SPECIFIERS_H
#include "../ft_printf.h"

char *get_conv(char *start, const char *t_convs);
char *get_flags(char *conv, const char *flags);
char *get_precision(char *conv, const char *t_convs);
char *get_min_width(char *conv, const char *flags, const char *t_convs);
#endif