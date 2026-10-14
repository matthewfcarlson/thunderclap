extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2c22d0[];
class Ref_2c22d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2c22d0 {
  public:
    void* vptr;
    void Fin();
};
class Action : public Base_2c22d0 {
  public:
    char pad[12];
    Ref_2c22d0* m;
    ~Action();
};
Action::~Action() {
    vptr = g_vftable_2c22d0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
