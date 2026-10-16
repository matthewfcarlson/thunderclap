#include "decls/address.h"
extern char gGlobal_35c800[];
extern char gGlobal2[];
void FUN_0035c800() {
    unsigned long long v = FUN_0027b020("commanche");
    *(unsigned int*)gGlobal_35c800 = (unsigned int)v;
    *(unsigned int*)gGlobal2 = (unsigned int)(v >> 32);
}
