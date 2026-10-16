#include "gen/fight.h"

extern "C" char DAT_0040fdb4[];
extern void* __cdecl Alloc(int);
class Target_12a570 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDirectionCondition>::vfunc_5() {
    Target_12a570* p = (Target_12a570*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_0040fdb4);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
