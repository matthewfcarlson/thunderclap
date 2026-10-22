extern "C" void _ReadWriteBarrier();
extern void* g_vftable_197f90[];
class Ref_197f90 {
  public:
    virtual void F0();
    virtual void Release();
};
class BeamEffect_197f90 {
  public:
    void* vptr;
    void* m4;
    char pad[0xc];
    Ref_197f90* m14;
    ~BeamEffect_197f90() throw();
};
BeamEffect_197f90::~BeamEffect_197f90() throw() {
    vptr = g_vftable_197f90;
    _ReadWriteBarrier();
    if (m14) {
        m14->Release();
        m14 = 0;
    }
    if (m4)
        m4 = 0;
}
