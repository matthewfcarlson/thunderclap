extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f7d0[];
class Ref_1f7d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f7d0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1f7d0 : public Base_1f7d0 {
  public:
    char pad[24];
    Ref_1f7d0* m;
    ~Obj_1f7d0();
};
Obj_1f7d0::~Obj_1f7d0() {
    vptr = g_vftable_1f7d0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
