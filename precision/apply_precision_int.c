#include "precision.h"

char	*add_precision_int(char *arg, char *precision) // precision goes first
{
	if (!precision)
		return (arg);
	
	if (ft_atoi(arg) < 0)
		precision = ft_itoa(ft_atoi(precision) + 1);
	return (add_padding_int(arg, precision, "0"));
}