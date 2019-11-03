#include <stdarg.h>
#include "../libft.h"
#include "t_convs.h"
char *get_char_arg(va_list args) // c
{
    char *s;

    s = ft_calloc(2, 1);
    s[0] = va_arg(args, int);
    return (s);
}

char *get_string_arg(va_list args) // s
{
    char *s;

    s = va_arg(args, char *);
    return (s ? s : ft_strdup("(null)"));
}

char *get_pointer_arg(va_list args) // p
{
    return (ft_itoa_base((int)va_arg(args,void *), "0123456789abcdef"));
}

char *get_dec_arg(va_list args) // d i
{
    return (ft_itoa(va_arg(args,int)));
}

char *get_int_arg(va_list args) // d i
{
    return (ft_itoa(va_arg(args,int)));
}

char *get_uint_arg(va_list args) // u 
{
    return (ft_utoa(va_arg(args,unsigned int)));
}

char *get_hex_arg(va_list args) // x
{
    return (ft_itoa_base(va_arg(args,int), "0123456789abcdef"));
}

char *get_uppercase_hex_arg(va_list args) // X
{
    return (ft_itoa_base(va_arg(args,int), "0123456789ABCDEF"));
}

char *get_percent_sign(va_list args) // X
{
    char *s;

    s = ft_calloc(2, 1);
    s[0] = '%';
    return (s);
}

void    init_dispatcher(void)
{
    d[0] = get_char_arg;
    d[1] = get_string_arg;
    d[2] = get_pointer_arg;
    d[3] = get_int_arg;
    d[4] = get_int_arg;
    d[5] = get_uint_arg;
    d[6] = get_hex_arg;
    d[7] = get_uppercase_hex_arg;
    d[8] = get_percent_sign;
}