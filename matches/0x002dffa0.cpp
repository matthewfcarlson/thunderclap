extern "C" void _ReadWriteBarrier();
extern int vt1_2dffa0;
extern int vt2_2dffa0;
class Ref_2dffa0 {
  public:
    virtual void f0();
    virtual void Release();
};
class PrimGroup_2dffa0 {
  public:
    void* vptr;
    ~PrimGroup_2dffa0() throw();
};
class PrimGroupOptimized_2dffa0 : public PrimGroup_2dffa0 {
  public:
    char p40[60];
    Ref_2dffa0* a40;
    char p58[20];
    Ref_2dffa0* a58;
    ~PrimGroupOptimized_2dffa0() throw();
};
PrimGroupOptimized_2dffa0::~PrimGroupOptimized_2dffa0() throw() {
    vptr = &vt1_2dffa0;
    _ReadWriteBarrier();
    if (a58) {
        a58->Release();
        a58 = 0;
    }
    vptr = &vt2_2dffa0;
    _ReadWriteBarrier();
    if (a40) {
        a40->Release();
        a40 = 0;
    }
}
