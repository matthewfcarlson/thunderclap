extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2c2a70[];
extern void* g_vftable2[];
class Ref_2c2a70 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2c2a70 {
  public:
    void* vptr;
    void Fin();
};

class Obj_2c2a70 : public Base_2c2a70 {
  public:
    char pad[0x1c - 4];
    Ref_2c2a70* m1c;
    Ref_2c2a70* m20;
    ~Obj_2c2a70() throw();
};
Obj_2c2a70::~Obj_2c2a70() throw() {
    vptr = g_vftable_2c2a70;
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
