// Same code shape as 0x001a9260 (propagated; names are from that function)
#include "gen/owners.h"
extern int __cdecl FUN_00344e74(owners::Obj_1a92e0*, int, void*, void*, int);
extern void* g1_1a92e0;
extern void* g2_1a92e0;
owners::Obj_1a92e0* owners::Obj_1a92e0::FUN_001a92e0() {
    owners::Obj_1a92e0* p = Get();
    if (FUN_00344e74(p, 0, &g1_1a92e0, &g2_1a92e0, 0))
        return p;
    return Tail();
}