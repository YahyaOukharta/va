#ifndef T_CONVS_H
# define T_CONVS_H
# include "../ft_printf.h"

char *get_char_arg(va_list args);
char *get_string_arg(va_list args);
char *get_pointer_arg(va_list args);
char *get_int_arg(va_list args);  // i & u 
char *get_uint_arg(va_list args);
char *get_hex_arg(va_list args);
char *get_uppercase_hex_arg(va_list args);

void init_t_dispatcher(void);
typedef char*(*t_disp)(va_list);
t_disp t_dispatcher[9];
#endif