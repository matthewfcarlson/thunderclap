extern void* __cdecl FUN_0008d690(unsigned int);
class Event {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    void Init(int);
    int a;
    int b;
    int c;
    int d;
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Event* vfunc_5();
};
Event* Factory::vfunc_5() {
    Event* p = (Event*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = 0x41c550;
        p->c = 0;
        p->d = 0;
        return p;
    }
    return (Event*)0;
}