#include "min_width.h"

void    init_w_dispatcher(void)
{
    p_dispatcher[0] = add_padding_char;
    p_dispatcher[1] = add_padding_string;
    p_dispatcher[2] = add_padding_ptr;
    p_dispatcher[3] = add_padding_int; //i
    p_dispatcher[4] = add_padding_int; //d
    p_dispatcher[5] = add_padding_uint;
    p_dispatcher[6] = add_padding_hex;
    p_dispatcher[7] = add_padding_hex;
    //p_dispatcher[8] = get_percent_sign;
}