#include "gen/fight.h"

class CCharacterSizeCondition_57540 {
  public:
    int x;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
extern "C" void* FUN_0008d690(unsigned int);
extern int g_vtable_57540[];

template <> void* fight::ConditionFactoryTemplate<CCharacterSizeCondition>::vfunc_5() {
    CCharacterSizeCondition_57540* p = (CCharacterSizeCondition_57540*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = (int)g_vtable_57540;
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
