class ConditionFactory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
struct Turning {
    int vptr;
    int x;
    int y;
    int z;
    int w;
    void Init(int);
};
extern "C" void* __cdecl Alloc(unsigned int);
extern int turning_vftable;
void* ConditionFactory::F() {
    Turning* p = (Turning*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (int)&turning_vftable;
        p->z = 0;
        p->w = 0;
        return p;
    }
    return 0;
}