#include "decls/data/game/global.h"

struct Hash_35db30 {
    unsigned int lo;
    unsigned int hi;
};

Hash_35db30 __cdecl FUN_0027b020(const void* p);

void FUN_0035db30() {
    Hash_35db30 h = FUN_0027b020(((unsigned char*)&DAT_0040048c));
    (*(unsigned int*)&DAT_004de728) = h.lo;
    (*(unsigned int*)&DAT_004de72c) = h.hi;
}
