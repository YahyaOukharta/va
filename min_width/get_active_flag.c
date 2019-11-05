#include "min_width.h"

char    get_active_flag(const char *flags)
{
    char flag;
    char *p;

    p = (char *)flags;
    flag = 0;
    while (p && *p)
	{
		if (*p == '0')
			flag = '0';
		if(*p == '-')
		{
			flag = '-';
			break;
		}
		p++;
	}
    return(flag);
}