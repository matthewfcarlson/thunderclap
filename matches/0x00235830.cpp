extern "C" char DAT_004279fc[];
struct Sub {
    void Init();
};
struct ParamValueConditionGroup {
    int vptr;
    char pad[4];
    Sub sub;
    ParamValueConditionGroup* vfunc_0(int);
};
extern void FUN_00267090(ParamValueConditionGroup*);
ParamValueConditionGroup* ParamValueConditionGroup::vfunc_0(int flags) {
    vptr = ((int)DAT_004279fc);
    sub.Init();
    if (flags & 1)
        FUN_00267090(this);
    return this;
}