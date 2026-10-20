#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041d3cc[];
class Condition_1ac890 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
class Sub_1ac890 {
  public:
    void Init();
};
class Event_TriggerVolumeNameCondition_1ac890 : public Condition_1ac890 {
  public:
    void Init(int);
    char pad[0x0c];
    Sub_1ac890 sub;
};
extern void* __cdecl Allocate(int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_TriggerVolumeNameCondition>::vfunc_5() {
    Event_TriggerVolumeNameCondition_1ac890* p = (Event_TriggerVolumeNameCondition_1ac890*)Allocate(0x18);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041d3cc);
        p->sub.Init();
        return (void*)(p);
    }
    return (void*)(0);
}
