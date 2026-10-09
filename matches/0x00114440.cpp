class InActiveCondition {
  public:
    unsigned int vptr;
    char pad4[8];
    int fieldC;
    char field10;
    void Init(int);
};
class ConditionFactoryTemplate {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual InActiveCondition* V5();
};
extern void* __cdecl FUN_0008d690(unsigned int);
extern int g_InActiveVftable;
InActiveCondition* ConditionFactoryTemplate::V5() {
    InActiveCondition* p = (InActiveCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (unsigned int)&g_InActiveVftable;
        p->fieldC = 0;
        p->field10 = 0;
        return p;
    }
    return 0;
}