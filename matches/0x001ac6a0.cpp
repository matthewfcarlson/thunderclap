extern "C" char DAT_0041d3ec[];
struct Obj_1ac6a0 {
    unsigned int vt;
    char pad[8];
    int value;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);
struct Factory_1ac6a0 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Obj_1ac6a0* F5();
};
Obj_1ac6a0* Factory_1ac6a0::F5() {
    Obj_1ac6a0* p = (Obj_1ac6a0*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_0041d3ec);
        p->value = 0;
        return p;
    }
    return 0;
}