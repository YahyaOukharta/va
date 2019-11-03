#include "precision.h"

void    init_p_dispatcher(void)
{
    p_dispatcher[0] = add_precision_c;
    p_dispatcher[1] = add_precision_s;
    p_dispatcher[2] = add_precision_hex;
    p_dispatcher[3] = add_precision_int;
    p_dispatcher[4] = add_precision_int;
    p_dispatcher[5] = add_precision_uint;
    p_dispatcher[6] = add_precision_hex;
    p_dispatcher[7] = add_precision_hex;
    //p_dispatcher[8] = get_percent_sign;
}