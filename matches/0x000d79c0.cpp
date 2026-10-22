extern "C" void _ReadWriteBarrier();
extern void* g_vftable_d79c0[];
class Ref_d79c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEControl_d79c0 {
  public:
    void* vptr;
    void Fin();
};
class FEBackground_d79c0 : public FEControl_d79c0 {
  public:
    char pad[0x14c];
    Ref_d79c0* m150;
    ~FEBackground_d79c0() throw();
};
FEBackground_d79c0::~FEBackground_d79c0() throw() {
    vptr = g_vftable_d79c0;
    _ReadWriteBarrier();
    if (m150) {
        m150->Release();
        m150 = 0;
    }
    Fin();
}
