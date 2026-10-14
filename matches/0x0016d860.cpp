class Condition {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init(int);
};
extern void* __cdecl FUN_0008d690(unsigned int);
extern int LocomotionVTable;
struct Locomotion_16d860 {
    int* vptr;
    char pad[8];
    int a;
    int b;
};
class Factory_16d860 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Condition* Create();
};
Condition* Factory_16d860::Create() {
    Condition* p = (Condition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        Locomotion_16d860* q = (Locomotion_16d860*)p;
        q->vptr = &LocomotionVTable;
        q->a = 0;
        q->b = 0;
        return p;
    }
    return 0;
}