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
struct Locomotion {
    int* vptr;
    char pad[8];
    int a;
    int b;
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Condition* Create();
};
Condition* Factory::Create() {
    Condition* p = (Condition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        Locomotion* q = (Locomotion*)p;
        q->vptr = &LocomotionVTable;
        q->a = 0;
        q->b = 0;
        return p;
    }
    return 0;
}