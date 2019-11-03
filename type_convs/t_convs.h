#include <stdarg.h>
#include "../libft.h"

char *get_char_arg(va_list args);
char *get_string_arg(va_list args);
char *get_pointer_arg(va_list args);
char *get_int_arg(va_list args);
char *get_uint_arg(va_list args);
char *get_hex_arg(va_list args);
char *get_uppercase_hex_arg(va_list args);
void init_dispatcher(void);
typedef char*(*dispatcher)(va_list);
dispatcher d[9];