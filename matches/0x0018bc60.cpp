extern "C" char DAT_0041928c[];
class SmartPropIsCargoCondition {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    int a, b, c, d;
    void Init(int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Factory_18bc60 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    SmartPropIsCargoCondition* V5();
};
SmartPropIsCargoCondition* Factory_18bc60::V5() {
    SmartPropIsCargoCondition* p = (SmartPropIsCargoCondition*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_0041928c);
        p->c = 0;
        return p;
    }
    return 0;
}