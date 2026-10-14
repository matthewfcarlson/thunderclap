extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1f4b0[];
class Ref_1f4b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1f4b0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1f4b0 : public Base_1f4b0 {
  public:
    char pad[24];
    Ref_1f4b0* m;
    ~Obj_1f4b0();
};
Obj_1f4b0::~Obj_1f4b0() {
    vptr = g_vftable_1f4b0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
