#include "compat/ptr.h"
#include "gen/fight.h"

extern void* __cdecl Alloc(hulk_uintptr);
class Condition_113f80 {
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

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::AIHistoryNameCondition>::vfunc_5() {
    Condition_113f80* p = (Condition_113f80*)Alloc(0x18);
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
