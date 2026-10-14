extern "C" char DAT_00416918[];
struct Obj_16dfc0 {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
extern Obj_16dfc0* __cdecl FUN_0008d690(unsigned int);
class Factory_16dfc0 {
  public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
};
void* Factory_16dfc0::f5() {
    Obj_16dfc0* p = FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_00416918);
        p->c = 0;
        p->d = 0;
        return p;
    }
    return 0;
}