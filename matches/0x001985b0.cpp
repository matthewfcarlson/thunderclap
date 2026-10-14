extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1985b0[];
class Ref_1985b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_1985b0 {
  public:
    void* vptr;
    void Fin();
};
class Obj_1985b0 : public Base_1985b0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_1985b0* m20;
    ~Obj_1985b0();
};
Obj_1985b0::~Obj_1985b0() {
    vptr = g_vftable_1985b0;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
