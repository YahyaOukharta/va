#include "precision.h"

char	*add_precision_hex(char *arg, char *precision)
{
	if (!precision)
		return (arg);
	return (add_padding(arg, 'x', precision, "0"));
}