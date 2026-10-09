class I {
  public:
    virtual void f0();
    virtual void f1();
};
class M {
  public:
    int dummy;
    void Call(void* a, int b);
};
class P {
  public:
    char pad0[4];
    I sub;
    char pad8[4];
    M* obj;
    int x10;
    char pad14[4];
    int zero;
};
class DriveCancelRequest {
  public:
    char pad[8];
    P* m;
    int vfunc_1();
};
int DriveCancelRequest::vfunc_1() {
    m->obj->Call(m, m->x10);
    m->sub.f0();
    m->zero = 0;
    m->sub.f1();
    return 1;
}
