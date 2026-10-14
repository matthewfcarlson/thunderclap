extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1d1e0[];
class Ref_1d1e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1d1e0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1d1e0 : public Base_1d1e0 {
  public:
    char pad[24];
    Ref_1d1e0* m;
    ~Obj_1d1e0();
};
Obj_1d1e0::~Obj_1d1e0() {
    vptr = g_vftable_1d1e0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
