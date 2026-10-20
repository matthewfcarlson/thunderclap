#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004288fc[];
typedef unsigned int u32_23cae0;
void* operator_new(unsigned int);
class Condition_23cae0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    void Init(int);
};
struct Tail_23cae0 {
    void InitTail();
};

template <> void* fight::ConditionFactoryTemplate<fight::SubConditionGroupCondition>::vfunc_5() {
    Condition_23cae0* p = (Condition_23cae0*)operator_new(0x10);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_004288fc);
        ((Tail_23cae0*)((char*)p + 12))->InitTail();
        return (void*)(p);
    }
    return (void*)(0);
}
