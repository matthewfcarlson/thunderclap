extern "C" char DAT_0040fd14[];
extern void* __cdecl Alloc(unsigned int);
class TargetDirectionYCondition {
  public:
    int v0;
    int pad4;
    int pad8;
    int x;
    int y;
};
class ConditionFactoryTemplate {
  public:
    TargetDirectionYCondition* vfunc_5();
};
class Base_12a2b0 {
  public:
    void Init(int);
};
TargetDirectionYCondition* ConditionFactoryTemplate::vfunc_5() {
    TargetDirectionYCondition* p = (TargetDirectionYCondition*)Alloc(0x14);
    if (p) {
        ((Base_12a2b0*)p)->Init(0);
        p->v0 = ((int)DAT_0040fd14);
        p->x = 0;
        p->y = 0;
        return p;
    }
    return 0;
}