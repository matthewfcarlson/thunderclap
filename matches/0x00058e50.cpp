extern "C" char DAT_003f9754[];
class CCollisionFlagCondition {
  public:
    int vf;
    void Init();
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class ConditionFactoryTemplate {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CCollisionFlagCondition* vfunc_5();
};
CCollisionFlagCondition* ConditionFactoryTemplate::vfunc_5() {
    CCollisionFlagCondition* p = (CCollisionFlagCondition*)FUN_0008d690(0x18);
    if (p) {
        p->Init();
        p->vf = ((int)DAT_003f9754);
        return p;
    }
    return 0;
}