extern "C" void _ReadWriteBarrier();
extern void* g_vftable_d79c0[];
class Ref_d79c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_d79c0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_d79c0 : public Base_d79c0 {
  public:
    char pad[0x14c];
    Ref_d79c0* m150;
    ~Obj_d79c0() throw();
};
Obj_d79c0::~Obj_d79c0() throw() {
    vptr = g_vftable_d79c0;
    _ReadWriteBarrier();
    if (m150) {
        m150->Release();
        m150 = 0;
    }
    Fin();
}
