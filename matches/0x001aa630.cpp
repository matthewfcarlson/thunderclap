extern "C" char DAT_0041c550[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Event_1aa630 {
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
class Factory_1aa630 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Event_1aa630* vfunc_5();
};
Event_1aa630* Factory_1aa630::vfunc_5() {
    Event_1aa630* p = (Event_1aa630*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_0041c550);
        p->c = 0;
        p->d = 0;
        return p;
    }
    return (Event_1aa630*)0;
}