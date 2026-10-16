#include "gen/fight.h"

extern "C" char DAT_003f6fec[];
class CCollisionPushbackDirectionCondition_57a00 {
  public:
    int pad0;
    int pad4;
    int pad8;
    int mA;
    int mB;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CCollisionPushbackDirectionCondition>::vfunc_5() {
    CCollisionPushbackDirectionCondition_57a00* p = (CCollisionPushbackDirectionCondition_57a00*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_003f6fec);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0x3fc90fdb;
        return (void*)(p);
    }
    return (void*)((void*)0);
}
