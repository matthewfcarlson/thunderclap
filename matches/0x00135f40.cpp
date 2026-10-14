extern "C" void _ReadWriteBarrier();
extern void* g_vftable_135f40[];
class Ref_135f40 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_135f40 {
  public:
    void* vptr;
    void Fin();
};
class Obj_135f40 : public Base_135f40 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_135f40* m20;
    Ref_135f40* m24;
    Ref_135f40* m28;
    ~Obj_135f40();
};
Obj_135f40::~Obj_135f40() {
    vptr = g_vftable_135f40;
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
