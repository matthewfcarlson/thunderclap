class Condition {
  public:
    int vt;
    char pad[8];
    int m;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Condition* Make();
};
Condition* Factory::Make() {
    Condition* p = (Condition*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vt = 0x40db64;
        p->m = 0;
        return p;
    }
    return 0;
}