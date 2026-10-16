#include "decls/address.h"
extern unsigned int g_first_35e140;
extern unsigned int g_second_35e140;

void FUN_0035e140() {
    unsigned __int64 result = FUN_0027b020("$MACRO_INSERT");
    g_first_35e140 = (unsigned int)result;
    g_second_35e140 = (unsigned int)(result >> 32);
}
