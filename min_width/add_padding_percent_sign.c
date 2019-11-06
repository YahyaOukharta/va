#include "min_width.h"

char	*add_padding_percent_sign(char *arg, char *width, const char *flags)
{
    char *s;
    (void)flags;
    s = add_padding_string(arg,width,flags);
	return (s);
}