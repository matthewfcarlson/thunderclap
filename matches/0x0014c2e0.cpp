extern "C" void* __cdecl alloc(unsigned int);
class Base {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* F();
};
class Cond {
  public:
    void Init(int);
};
class Sub {
  public:
    void Init();
};
class Factory : public Base {
  public:
    char pad[8];
    int field;
    Sub sub;
    void* F();
};
void* Factory::F() {
    Factory* p = (Factory*)alloc(0x18);
    if (p) {
        ((Cond*)p)->Init(0);
        *(int*)p = 0x413578;
        p->field = 0;
        p->sub.Init();
        return p;
    }
    return 0;
}