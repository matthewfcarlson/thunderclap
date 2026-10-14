extern "C" char DAT_0040db64[];
class Condition {
  public:
    int vt;
    char pad[8];
    int m;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);
class Factory_1147b0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Condition* Make();
};
Condition* Factory_1147b0::Make() {
    Condition* p = (Condition*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_0040db64);
        p->m = 0;
        return p;
    }
    return 0;
}