// Same code shape as 0x001a9260 (propagated; names are from that function)
#include "gen/owners.h"
struct Obj_1a92a0 {
    Obj_1a92a0* Get();
    Obj_1a92a0* Target();
};
extern int __cdecl FUN_00344e74(Obj_1a92a0*, int, void*, void*, int);
extern void* g1_1a92a0;
extern void* g2_1a92a0;
Obj_1a92a0* Obj_1a92a0::Target() {
    Obj_1a92a0* p = Get();
    if (FUN_00344e74(p, 0, &g1_1a92a0, &g2_1a92a0, 0))
        return p;
    return ((Obj_1a92a0 *)((owners::Obj_1a6e50 *)this)->FUN_001a6e50());
}