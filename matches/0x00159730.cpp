extern "C" char DAT_00414110[];
extern "C" void* __cdecl alloc(unsigned int);
struct Obj_159730 {
    int vf;
    char pad[8];
    char flag;
    void Init(int);
};
class Factory_159730 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    Obj_159730* vfunc_5();
};
Obj_159730* Factory_159730::vfunc_5() {
    Obj_159730* p = (Obj_159730*)alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_00414110);
        p->flag = 1;
        return p;
    }
    return 0;
}