extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_23e0d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_23e0d0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_23e0d0 : public Base_23e0d0 {
  public:
    char pad[28];
    Ref_23e0d0* m;
    ~Obj_23e0d0() throw();
};
Obj_23e0d0::~Obj_23e0d0() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}
