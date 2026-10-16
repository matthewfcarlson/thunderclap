#include "decls/address.h"
extern char gFirst_35d050[4];
extern char gSecond_35d050[4];
void __cdecl FUN_0035d050() {
    unsigned long long v = FUN_0027b020("$MACRO_INSERT");
    *(unsigned int*)gFirst_35d050 = (unsigned int)v;
    *(unsigned int*)gSecond_35d050 = (unsigned int)(v >> 32);
}
