extern "C" char DAT_004169b8[];
struct Obj_16e320 {
    int vf;
    char pad[8];
    unsigned char flag;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);
class Factory_16e320 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual Obj_16e320* F();
};
Obj_16e320* Factory_16e320::F() {
    Obj_16e320* p = (Obj_16e320*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_004169b8);
        p->flag = 1;
        return p;
    }
    return (Obj_16e320*)0;
}