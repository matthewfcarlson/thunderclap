#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" char DAT_0048d5bc[];
extern "C" char DAT_004c26a4[];
extern int __cdecl Find(owners::Obj_1a6e50*, int, const char*, const char*, int);
owners::Obj_1a6e50* owners::Obj_1a6e50::FUN_001a6e50() {
    owners::Obj_1a6e50* p = Get();
    while (p && Find(p, 0, (const char*)((hulk_intptr)DAT_0048d5bc), (const char*)((hulk_intptr)DAT_004c26a4), 0) == 0)
        p = Get();
    return p;
}