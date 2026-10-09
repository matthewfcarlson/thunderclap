struct Obj {
    unsigned int vt;
    char pad[8];
    int value;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);
struct Factory {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Obj* F5();
};
Obj* Factory::F5() {
    Obj* p = (Obj*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vt = 0x41d3ec;
        p->value = 0;
        return p;
    }
    return 0;
}