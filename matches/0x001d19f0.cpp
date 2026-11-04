#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"

extern int __cdecl Query(int, int);
extern int __cdecl Format(int, int, const char*, ...);
extern void __cdecl Finish(int, int);
bool owners::Obj_1d19f0::FUN_001d19f0(hulk_intptr a, int b, char flag) {
    int x = Query(field, -1);
    bool r = true;
    if (x == 0) {
        r = false;
    } else {
        Format(((int)a), b, (const char*)((hulk_intptr)((char*)&DAT_003f3f38)), x);
    }
    if (flag)
        Finish(field, -2);
    return r;
}