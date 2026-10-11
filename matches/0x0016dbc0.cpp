extern "C" char DAT_00416838[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetHealthPercentCondition {
  public:
    void Init(int);
    unsigned int vt;
    int pad[2];
    int a, b;
};
class ConditionFactoryTemplate {
  public:
    void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    TargetHealthPercentCondition* p = (TargetHealthPercentCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_00416838);
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}