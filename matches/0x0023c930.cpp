#include "compat/ptr.h"
extern "C" char DAT_004288fc[];
class SubConditionGroupCondition;
struct Part_23c930 {
    char pad[12];
    void Init();
};
class SubConditionGroupCondition {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual SubConditionGroupCondition* vfunc_5(int);
    virtual void v6();
    void Finalize();
};
extern void __cdecl DestroySub(SubConditionGroupCondition*);
SubConditionGroupCondition* SubConditionGroupCondition::vfunc_5(int flags) {
    Part_23c930* p = (Part_23c930*)((char*)this + 12);
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_004288fc);
    p->Init();
    Finalize();
    if (flags & 1)
        DestroySub(this);
    return this;
}