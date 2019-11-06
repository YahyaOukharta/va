#include "precision.h"

char	*add_precision_ptr(char *arg, char *precision)
{
	if (!precision)
		return (arg);
	return (add_padding_hex(arg, precision, "0"));
}