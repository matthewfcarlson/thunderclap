extern "C" void* __cdecl alloc(unsigned int);
struct Obj {
    int vf;
    char pad[8];
    char flag;
    void Init(int);
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    Obj* vfunc_5();
};
Obj* Factory::vfunc_5() {
    Obj* p = (Obj*)alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = 0x414110;
        p->flag = 1;
        return p;
    }
    return 0;
}