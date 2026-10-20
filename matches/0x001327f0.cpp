#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00411244[];
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Obj_1327f0 {
  public:
    void Init(int);
    char pad[12];
    int z;
    char c;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::UnlockableCondition>::vfunc_5() {
    Obj_1327f0* p = (Obj_1327f0*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_00411244);
        p->z = 0;
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
