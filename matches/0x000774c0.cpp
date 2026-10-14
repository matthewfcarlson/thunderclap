extern "C" char DAT_003fc058[];
extern "C" void* __cdecl FUN_0008d690(int);
struct Obj_774c0 {
    int vptr;
    int x4;
    int m8;
    int mc;
    int m10;
    void Init();
};
class Factory_774c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj_774c0* vfunc_5();
};
Obj_774c0* Factory_774c0::vfunc_5() {
    Obj_774c0* p = (Obj_774c0*)FUN_0008d690(0x14);
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