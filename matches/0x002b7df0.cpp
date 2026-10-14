extern "C" void _ReadWriteBarrier();
extern void* g_vftable_0042e6e4[];
extern void* g_vftable2[];
class Ref_2b7df0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2b7df0 {
  public:
    void* vptr;
    void Fin();
};

class Obj_2b7df0 : public Base_2b7df0 {
  public:
    char pad[0x1c - 4];
    Ref_2b7df0* m1c;
    Ref_2b7df0* m20;
    ~Obj_2b7df0() throw();
};
Obj_2b7df0::~Obj_2b7df0() throw() {
    vptr = g_vftable_0042e6e4;
    _ReadWriteBarrier();
    if (m1c) {
        m1c->Release();
        m1c = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    vptr = g_vftable2;
}
