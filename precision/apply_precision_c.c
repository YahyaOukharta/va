#include "precision.h"

char	*add_precision_c(char *arg, char *precision)
{
    char *s;
    (void)precision;
	s = ft_strdup(arg);
    free(arg);
    return (s);
}