extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2a35f0[];
class Ref_2a35f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2a35f0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2a35f0 : public Base_2a35f0 {
  public:
    char pad[12];
    Ref_2a35f0* m;
    ~Obj_2a35f0();
};
Obj_2a35f0::~Obj_2a35f0() {
    vptr = g_vftable_2a35f0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
