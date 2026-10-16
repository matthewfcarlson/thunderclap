// Same code shape as 0x00113f80 (propagated; names are from that function)
#include "gen/fight.h"

extern void* __cdecl Alloc(unsigned int);
class Condition_16e470 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void Init(int);
    int x;
    int y;
    int z;
    int w;
    int q;
};
extern int AIHistoryNameCondition_vftable;

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::HealthCondition>::vfunc_5() {
    Condition_16e470* p = (Condition_16e470*)Alloc(0x18);
    void* result;
    if (p) {
        p->Init(0);
        *(int**)p = &AIHistoryNameCondition_vftable;
        p->z = 0;
        p->w = 0;
        p->q = 0;
        result = p;
    } else
        result = 0;
    return (void*)(result);
}
