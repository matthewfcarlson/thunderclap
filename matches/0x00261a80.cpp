// Same code shape as 0x0025c000 (propagated; names are from that function)
#include "gen/owners.h"
extern "C" bool __cdecl Check(void*, void*);
int owners::Target_261a80::FUN_00261a80(void* p) {
    if (Check(p, this) && Check(p, (char*)this + 4))
        return 1;
    return 0;
}