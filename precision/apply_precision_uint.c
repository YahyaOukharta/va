#include "precision.h"

char	*add_precision_uint(char *arg, char *precision)
{
	if (!precision)
		return (arg);
	return (add_padding_uint(arg, precision, "0"));
}