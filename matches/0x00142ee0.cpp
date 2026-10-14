extern "C" char DAT_00412ab0[];
class Obj_142ee0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Obj_142ee0* v5();
    void Init(int);
    int a;
    char pad[4];
    int b;
    int c;
};
extern "C" void* __cdecl Alloc(unsigned int);
Obj_142ee0* Obj_142ee0::v5() {
    Obj_142ee0* p = (Obj_142ee0*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_00412ab0);
        p->b = 0;
        p->c = 0;
        return p;
    }
    return 0;
}