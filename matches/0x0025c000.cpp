#include "gen/owners.h"
extern "C" bool __cdecl Check(void*, void*);
int owners::Target_25c000::FUN_0025c000(void* p) {
    if (Check(p, this) && Check(p, (char*)this + 4))
        return 1;
    return 0;
}