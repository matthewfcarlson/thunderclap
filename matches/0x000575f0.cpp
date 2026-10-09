class CClimbableCondition {
  public:
    int vt;
    void Init(int);
    int a;
    int b;
    int c;
    int d;
    char e;
};
extern int climbVftable;
extern void* __cdecl FUN_0008d690(unsigned int);
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CClimbableCondition* vfunc_5();
};
CClimbableCondition* Factory::vfunc_5() {
    CClimbableCondition* p = (CClimbableCondition*)FUN_0008d690(0x18);
    if (p) {
        p->Init(0);
        p->vt = (int)&climbVftable;
        p->c = 0;
        p->d = 0x3e860a92;
        p->e = 0;
        return p;
    }
    return 0;
}