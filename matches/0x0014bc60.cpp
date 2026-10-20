#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00413598[];
extern void* __cdecl alloc(unsigned int);
class GrappleAttachedCondition_14bc60 {
  public:
    GrappleAttachedCondition_14bc60(int);
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[8];
    unsigned char flag;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleAttachedCondition>::vfunc_5() {
    GrappleAttachedCondition_14bc60* p = (GrappleAttachedCondition_14bc60*)alloc(16);
    if (p) {
        p->GrappleAttachedCondition_14bc60::GrappleAttachedCondition_14bc60(0);
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_00413598);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
