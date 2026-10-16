#include "gen/fight.h"

extern "C" char DAT_00414150[];
extern "C" void* __cdecl Alloc(unsigned int);
class CollisionChargeCondition_159880 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    char pad[8];
    int a;
    int b;
    char c;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionChargeCondition>::vfunc_5() {
    CollisionChargeCondition_159880* p = (CollisionChargeCondition_159880*)Alloc(0x18);
    if (p) {
        p->Init(0);
        *(unsigned long*)p = ((int)DAT_00414150);
        p->a = 0;
        p->b = 0;
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
