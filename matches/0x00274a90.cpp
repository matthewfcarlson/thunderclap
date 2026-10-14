class I_274a90 {
  public:
    virtual void f0();
    virtual void f1();
};
class M_274a90 {
  public:
    int dummy;
    void Call(void* a, int b);
};
class P_274a90 {
  public:
    char pad0[4];
    I_274a90 sub;
    char pad8[4];
    M_274a90* obj;
    int x10;
    char pad14[4];
    int zero;
};
class DriveCancelRequest {
  public:
    char pad[8];
    P_274a90* m;
    int vfunc_1();
};
int DriveCancelRequest::vfunc_1() {
    m->obj->Call(m, m->x10);
    m->sub.f0();
    m->zero = 0;
    m->sub.f1();
    return 1;
}
