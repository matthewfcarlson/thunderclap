#include "compat/ptr.h"
extern "C" char DAT_004279fc[];
struct Sub_235830 {
    void Init();
};
struct ParamValueConditionGroup {
    int vptr;
    char pad[4];
    Sub_235830 sub;
    ParamValueConditionGroup* vfunc_0(int);
};
extern void FUN_00267090(ParamValueConditionGroup*);
ParamValueConditionGroup* ParamValueConditionGroup::vfunc_0(int flags) {
    vptr = ((hulk_intptr)DAT_004279fc);
    sub.Init();
    if (flags & 1)
        FUN_00267090(this);
    return this;
}