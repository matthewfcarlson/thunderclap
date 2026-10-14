extern "C" char DAT_00413f70[];
void* __cdecl Alloc(unsigned int);
struct Obj_158f40 {
    unsigned int vt;
    int pad[2];
    int a;
    int b;
    void Init(int);
};
struct Factory_158f40 {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Obj_158f40* V5();
};
Obj_158f40* Factory_158f40::V5() {
    Obj_158f40* p = (Obj_158f40*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_00413f70);
        p->a = 0;
        p->b = 0;
        return p;
    }
    return 0;
}
