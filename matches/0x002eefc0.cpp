#include "gen/owners.h"
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
void owners::Obj_2eefc0::FUN_002eefc0() {
    Base();
    if (p10)
        operator delete(p10);
    operator delete[](p14);
    operator delete[](p24);
    p60 = p5c;
    if (p60)
        operator delete[](p60);
    p50 = p4c;
    if (p50)
        operator delete[](p50);
    p40 = p3c;
    if (p40)
        operator delete[](p40);
    p30 = p2c;
    if (p30)
        operator delete[](p30);
    p4 = p0;
    if (p4)
        operator delete[](p4);
}