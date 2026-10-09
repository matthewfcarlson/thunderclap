extern "C" void* __cdecl Alloc(unsigned int);
class Obj {
  public:
    int vf;
    int a;
    int b;
    int c;
    Obj(int);
};
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual Obj* vfunc_5();
};
Obj* Factory::vfunc_5() {
    Obj* p = (Obj*)Alloc(0x10);
    if (p) {
        p->Obj::Obj(0);
        p->vf = 0x4281f0;
        p->c = 0;
        return p;
    }
    return 0;
}