extern "C" char DAT_003fc058[];
extern "C" void* __cdecl FUN_0008d690(int);
struct Obj {
    int vptr;
    int x4;
    int m8;
    int mc;
    int m10;
    void Init();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj* vfunc_5();
};
Obj* Factory::vfunc_5() {
    Obj* p = (Obj*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        p->vptr = ((int)DAT_003fc058);
        p->mc = 0;
        p->m10 = 0;
        p->m8 = 1;
        return p;
    }
    return 0;
}