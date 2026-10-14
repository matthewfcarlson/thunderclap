class SimStateArticulated {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5(int);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    char pad[0x84];
    void* ptr;
};
struct Obj1_2fd5e0 {
    void* f490(int);
};
struct Obj2_2fd5e0 {
    void* edf();
};
struct Obj3_2fd5e0 {
    void* f100();
};
void* SimStateArticulated::vfunc_5(int x) {
    if (x >= 0 && ptr) {
        Obj1_2fd5e0* a = (Obj1_2fd5e0*)ptr;
        Obj2_2fd5e0* b = (Obj2_2fd5e0*)a->f490(x);
        Obj3_2fd5e0* c = (Obj3_2fd5e0*)b->edf();
        return (char*)c->f100() + 0x30;
    }
    return (char*)this + 0x40;
}