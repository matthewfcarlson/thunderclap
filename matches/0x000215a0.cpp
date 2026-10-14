extern "C" void _ReadWriteBarrier();
extern void* g_vftable_215a0[];
class Ref_215a0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_215a0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_215a0 : public Base_215a0 {
  public:
    char pad[24];
    Ref_215a0* m;
    ~Obj_215a0();
};
Obj_215a0::~Obj_215a0() {
    vptr = g_vftable_215a0;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
