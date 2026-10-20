// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// FUN_00087990 @ 0x00087990
#include "compat/ptr.h"
extern "C" {
struct Run_87990 { void fn86(); };
struct Obj_87990 {
    char pad0[0x54];
    hulk_intptr field54;
    char pad58[0x9d - 0x58];
    char flag9d;
};
extern Obj_87990* gObj_87990;
void __cdecl thunk();
void __cdecl fnTail();
}
void target() {
    Obj_87990* p = gObj_87990;
    if (p && p->flag9d && p->field54) {
        ((Run_87990*)p->field54)->fn86();
        return;
    }
    thunk();
    fnTail();
}