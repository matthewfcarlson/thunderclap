#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041b248[];
extern void* __cdecl Alloc(unsigned int);
class Item_1a0d30 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropGrabbableIsMissileCondition>::vfunc_5() {
    Item_1a0d30* p = (Item_1a0d30*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041b248);
        *((char*)p + 0xc) = 1;
    } else {
        return (void*)(0);
    }
    return (void*)(p);
}
