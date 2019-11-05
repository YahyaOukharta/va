#ifndef MIN_WIDTH_H
# define MIN_WIDTH_H
# include "../ft_printf.h"

char	*add_padding_char(char *arg, char *width, const char *flags);
char	*add_padding_string(char *arg, char *width, const char *flags);
char	*add_padding_ptr(char *arg, char *width, const char *flags);
char	*add_padding_int(char *arg, char *width, const char *flags);
char	*add_padding_uint(char *arg, char *width, const char *flags);
char	*add_padding_hex(char *arg, char *width, const char *flags);
char	*add_padding_percent_sign(char *arg, char *width, const char *flags);

char    get_active_flag(const char *flags);

void	init_w_dispatcher(void);
typedef char*(*w_disp)(char *, char *, const char *);
w_disp w_dispatcher[9];
#endif