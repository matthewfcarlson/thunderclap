extern "C" void _ReadWriteBarrier();
extern void* g_vftable_151f80[];
class Ref_151f80 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_151f80 {
  public:
    void* vptr;
    void Fin();
};
class Obj_151f80 : public Base_151f80 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_151f80* m20;
    Ref_151f80* m24;
    Ref_151f80* m28;
    ~Obj_151f80();
};
Obj_151f80::~Obj_151f80() {
    vptr = g_vftable_151f80;
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
