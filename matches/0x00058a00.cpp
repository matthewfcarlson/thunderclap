extern "C" char DAT_003f7178[];
class CSmartPropTypeCondition {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    void Init(int);
    char pad[8];
    int a;
    int b;
};
extern "C" CSmartPropTypeCondition* Alloc(unsigned int);
class Factory {
  public:
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    CSmartPropTypeCondition* Create();
};
CSmartPropTypeCondition* Factory::Create() {
    CSmartPropTypeCondition* p = Alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_003f7178);
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}