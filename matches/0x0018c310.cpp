extern "C" void* __cdecl alloc(unsigned int);
extern int vtable_18c310;
class Prop_18c310 {
  public:
    int vptr;
    int pad;
    int x;
    int a;
    int b;
    int c;
    void Init();
};
class Factory_18c310 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Make();
};
void* Factory_18c310::Make() {
    Prop_18c310* p = (Prop_18c310*)alloc(0x18);
    if (p) {
        p->Init();
        p->vptr = (int)&vtable_18c310;
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->x = 1;
        return p;
    }
    return 0;
}