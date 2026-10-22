// Same code shape as 0x00113f80 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/fight.h"

extern void* __cdecl Alloc(hulk_uintptr);
class GameStateCondition_132740 {
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

template <> void* fight::ConditionFactoryTemplate<hulkfight::MissionProgressCondition>::vfunc_5() {
    GameStateCondition_132740* p = (GameStateCondition_132740*)Alloc(0x18);
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
