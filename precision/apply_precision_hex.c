#include "precision.h"

char	*add_precision_hex(char *arg, char *precision)
{
	char *s;

	if (!precision)
		return (arg);
	s = add_padding_hex(arg, precision, "0");
	return (s);
}