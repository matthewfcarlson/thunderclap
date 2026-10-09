extern "C" void* __cdecl Alloc(int);
struct Obj {
    int vf;
    int pad[4];
    void Init(int);
};
class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Obj* F();
};
Obj* Factory::F() {
    Obj* p = (Obj*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vf = 0x413fd0;
        p->pad[2] = 0;
        p->pad[3] = 0;
        return p;
    }
    return 0;
}