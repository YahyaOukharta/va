#include "min_width.h"

void    init_w_dispatcher(void)
{
    w_dispatcher[0] = add_padding_char;
    w_dispatcher[1] = add_padding_string;
    w_dispatcher[2] = add_padding_ptr;
    w_dispatcher[3] = add_padding_int; //i
    w_dispatcher[4] = add_padding_int; //d
    w_dispatcher[5] = add_padding_uint;
    w_dispatcher[6] = add_padding_hex;
    w_dispatcher[7] = add_padding_hex;
    w_dispatcher[8] = add_padding_percent_sign;
}