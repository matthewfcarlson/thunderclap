extern "C" void* __cdecl alloc(unsigned int);
extern int vtable;
class Prop {
  public:
    int vptr;
    int pad;
    int x;
    int a;
    int b;
    int c;
    void Init();
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Make();
};
void* Factory::Make() {
    Prop* p = (Prop*)alloc(0x18);
    if (p) {
        p->Init();
        p->vptr = (int)&vtable;
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->x = 1;
        return p;
    }
    return 0;
}