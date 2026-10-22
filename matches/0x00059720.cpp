extern "C" void _ReadWriteBarrier();
extern void* g_vftable_59720[];
class Ref_59720 {
  public:
    virtual void F0();
    virtual void Release();
};
class Params_59720 {
  public:
    void* vptr;
    void Fin();
};
class CFightParams_59720 : public Params_59720 {
  public:
    char pad[0xc - 4];
    Ref_59720* mc;
    Ref_59720* m10;
    ~CFightParams_59720();
};
CFightParams_59720::~CFightParams_59720() {
    vptr = g_vftable_59720;
    _ReadWriteBarrier();
    if (m10) {
        m10->Release();
        m10 = 0;
    }
    if (mc) {
        mc->Release();
        mc = 0;
    }
    Fin();
}
