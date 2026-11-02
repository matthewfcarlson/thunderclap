#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004168f8[];
extern "C" void* __cdecl FUN_0008d690(hulk_uintptr);
class Obj_16df20 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::InLoadedRoomCondition>::vfunc_5() {
    Obj_16df20* p = (Obj_16df20*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004168f8);
        *((unsigned char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
