#include "gen/fight.h"

class Base_1ac7e0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
};
class WaypointCondition : public Base_1ac7e0 {
  public:
    void Init(int);
    char pad[8];
    int m0;
    int m1;
};
extern char VT_1ac7e0[];
extern void* __cdecl Allocate(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_WaypointCondition>::vfunc_5() {
    WaypointCondition* p = (WaypointCondition*)Allocate(0x14);
    if (p) {
        p->Init(0);
        *(void**)p = VT_1ac7e0;
        p->m0 = 0;
        p->m1 = -1;
        return (void*)(p);
    }
    return (void*)(0);
}
