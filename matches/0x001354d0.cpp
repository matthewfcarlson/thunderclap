extern "C" void _ReadWriteBarrier();
extern void* g_vftable_00411dc4[];
class Ref_1354d0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1354d0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1354d0 : public Base_1354d0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1354d0* m20;
    Ref_1354d0* m24;
    Ref_1354d0* m28;
    ~Obj_1354d0();
};
Obj_1354d0::~Obj_1354d0() {
    vptr = g_vftable_00411dc4;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
