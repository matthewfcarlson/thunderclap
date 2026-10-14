extern "C" void _ReadWriteBarrier();
extern void* g_vftable_2b7c00[];
class Ref_2b7c00 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_2b7c00 {
  public:
    void* vptr;
    void Fin();
};
class Obj_2b7c00 : public Base_2b7c00 {
  public:
    char pad[0x54];
    Ref_2b7c00* m58;
    Ref_2b7c00* m5c;
    Ref_2b7c00* m60;
    Ref_2b7c00* m64;
    Ref_2b7c00* m68;
    Ref_2b7c00* m6c;
    Ref_2b7c00* m70;
    ~Obj_2b7c00();
};
Obj_2b7c00::~Obj_2b7c00() {
    vptr = g_vftable_2b7c00;
    _ReadWriteBarrier();
    if (m58) {
        m58->Release();
        m58 = 0;
    }
    if (m5c) {
        m5c->Release();
        m5c = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (m68) {
        m68->Release();
        m68 = 0;
    }
    if (m6c) {
        m6c->Release();
        m6c = 0;
    }
    if (m70) {
        m70->Release();
        m70 = 0;
    }
    Fin();
}
