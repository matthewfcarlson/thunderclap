extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2e13e0[];
class Ref_2e13e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2e13e0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2e13e0 : public Base_2e13e0 {
  public:
    char pad[4];
    Ref_2e13e0* m;
    ~Obj_2e13e0();
};
Obj_2e13e0::~Obj_2e13e0() {
    vptr = g_vftable_2e13e0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
