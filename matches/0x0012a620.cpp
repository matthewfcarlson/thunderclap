#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040fdd4[];
typedef unsigned int u32_12a620;
typedef unsigned char u8;
extern void* Alloc(unsigned int);
class InitBase_12a620 {
  public:
    void Init(int);
};
struct TargetDistanceYCondition_12a620 : InitBase_12a620 {
    u32_12a620 vptr;
    u32_12a620 pad1;
    u32_12a620 pad2;
    int a;
    int b;
    u8 c, d, e;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetDistanceYCondition>::vfunc_5() {
    TargetDistanceYCondition_12a620* p = (TargetDistanceYCondition_12a620*)Alloc(0x18);
    if (p != 0) {
        p->Init(0);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->vptr = ((hulk_intptr)DAT_0040fdd4);
        return (void*)(p);
    }
    return (void*)(0);
}
