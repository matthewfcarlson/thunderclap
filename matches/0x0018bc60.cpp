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
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    SmartPropIsCargoCondition* V5();
};
SmartPropIsCargoCondition* Factory::V5() {
    SmartPropIsCargoCondition* p = (SmartPropIsCargoCondition*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(int*)p = 0x41928c;
        p->c = 0;
        return p;
    }
    return 0;
}