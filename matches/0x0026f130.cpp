class X_26f130 {
  public:
    virtual void f();
    virtual void g();
    int n;
};
// core::Drive's AddRef: the reference count under its IMutable base (+0xc; records.h CoreDrive)
class Drive_26f130 {
  public:
    virtual void vfunc_0();
    const void* vftableObject;
    int heap;
    X_26f130 x;
};
void Drive_26f130::vfunc_0() {
    X_26f130* p = &x;
    p->f();
    ++p->n;
    p->g();
}
