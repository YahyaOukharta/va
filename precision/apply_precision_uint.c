#include "precision.h"

char	*add_precision_uint(char *arg, char *precision)
{
	if (!precision)
		return (arg);
	return (add_padding(arg, 'u', precision, "0"));
}