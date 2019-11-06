#include "precision.h"

char	*add_precision_uint(char *arg, char *precision)
{
	char *s;
	if (!precision)
		return (arg);
	s = add_padding_uint(arg, precision, "0");
	//free(arg);
	return (s);
}