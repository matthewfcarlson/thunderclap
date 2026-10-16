#include "decls/address.h"
extern unsigned int gLower;
extern unsigned int gUpper;
void FUN_0035d8d0() {
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    gLower = (unsigned int)v;
    gUpper = (unsigned int)(v >> 32);
}
