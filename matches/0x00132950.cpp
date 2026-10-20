#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00411284[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
struct DebugPrintCondition_132950 {
    hulk_uintptr vptr;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::DebugPrintCondition>::vfunc_5() {
    DebugPrintCondition_132950* p = (DebugPrintCondition_132950*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = ((hulk_intptr)DAT_00411284);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
