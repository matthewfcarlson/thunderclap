extern "C" void _ReadWriteBarrier();
extern void* g_vA[];
class Ref_1733d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1733d0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1733d0 : public Base_1733d0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_1733d0* m20;
    ~Obj_1733d0() throw();
};
Obj_1733d0::~Obj_1733d0() throw() {
    vptr = g_vA;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
