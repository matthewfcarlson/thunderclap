class CSmartPropWeaponTypeCondition {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    int x4;
    int x8;
    int value;
    int type;
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class ConditionFactoryTemplate {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
    void* Vfunc5();
};
void* ConditionFactoryTemplate::Vfunc5() {
    CSmartPropWeaponTypeCondition* p = (CSmartPropWeaponTypeCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = 0x3f7154;
        p->value = 0;
        p->type = -1;
        return p;
    }
    return (void*)0;
}