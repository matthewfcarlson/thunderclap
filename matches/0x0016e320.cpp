struct Obj {
    int vf;
    char pad[8];
    unsigned char flag;
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
    virtual Obj* F();
};
Obj* Factory::F() {
    Obj* p = (Obj*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = 0x4169b8;
        p->flag = 1;
        return p;
    }
    return (Obj*)0;
}