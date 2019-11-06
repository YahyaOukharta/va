#ifndef PRECISION_H
# define PRECISION_H
# include "../ft_printf.h"

char	*add_precision_c(char *arg, char *precision);
char	*add_precision_s(char *arg, char *precision);
char	*add_precision_ptr(char *arg, char *precision);
char	*add_precision_int(char *arg, char *precision);
char	*add_precision_uint(char *arg, char *precision);
char	*add_precision_hex(char *arg, char *precision);
char	*add_precision_percent_sign(char *arg, char *precision);

void    init_p_dispatcher(void);

typedef char*(*p_disp)(char *, char *);
p_disp p_dispatcher[11];

#endif