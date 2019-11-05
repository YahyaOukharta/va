#include "precision.h"

char	*add_precision_int(char *arg, char *precision) // precision goes first
{
	if (!precision)
		return (arg);
	return (add_padding_int(arg, precision, "0"));
}