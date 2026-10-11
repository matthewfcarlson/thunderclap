extern void* vWSM[];
extern void* vPool[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
extern void FUN_00263e90();
extern void FUN_00267110(int);
extern void FUN_00267090(void*);
struct Pool {
    void* vf;
    char b4;
    char b5;
    char pad6[0x20];
    short w26;
    char pad28[4];
    void* p2c;
    Ref* p30;
    char pad34[4];
    Ref* p38;
    void Fini() throw();
};
void Pool::Fini() throw() {
    vf = vPool;
    if (p38) {
        ((void(__fastcall*)(Ref*))FUN_00263e90)(p38);
        p38 = 0;
    }
    if (p30)
        FUN_00267110(w26);
    if (p30) {
        p30->Release();
        p30 = 0;
    }
    if (p2c) {
        FUN_00267090(p2c);
        p2c = 0;
    }
    b4 = 0;
    b5 = 0;
    w26 = 0;
}
struct Target {
    void* vf;
    char pad[0x44];
    Pool a[0x14];
    Pool b[2];
    void Dtor() throw();
};
void Target::Dtor() throw() {
    vf = vWSM;
    Pool* p = b + 2;
    for (int i = 2; i; --i) {
        --p;
        p->Fini();
    }
    p = a + 0x14;
    for (int i = 0x14; i; --i) {
        --p;
        p->Fini();
    }
}
