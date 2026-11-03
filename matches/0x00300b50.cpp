#include "gen/owners.h"
extern void __cdecl Release(void*);
void owners::Obj_300b50::FUN_00300b50() {
    Init();
    void* p = p4;
    q4 = p;
    if (p)
        Release(p);
    p = p3;
    q3 = p;
    if (p)
        Release(p);
    p = p2;
    q2 = p;
    if (p)
        Release(p);
    p = p1;
    q1 = p;
    if (p)
        Release(p);
    p = p0;
    q0 = p;
    if (p)
        Release(p);
}