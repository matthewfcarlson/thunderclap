extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042fb84[];
class Ref_2e13b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2e13b0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2e13b0 : public Base_2e13b0 {
  public:
    char pad[4];
    Ref_2e13b0* m;
    ~Obj_2e13b0();
};
Obj_2e13b0::~Obj_2e13b0() {
    vptr = g_vftable_0042fb84;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
