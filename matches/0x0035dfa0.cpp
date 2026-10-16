#include "decls/address.h"
extern unsigned int gKey;
extern unsigned int gValue;
void FUN_0035dfa0() {
    unsigned long long v = FUN_0027b020("$MACRO_DEFINE");
    gKey = (unsigned int)v;
    gValue = (unsigned int)(v >> 32);
}
