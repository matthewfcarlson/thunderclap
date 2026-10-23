extern "C" void _ReadWriteBarrier();
extern void* DAT_0040c390[];
extern void* DAT_0040bfc0[];
class Ref_e8730 {
  public:
    virtual void F0();
    virtual void Release();
};
void operator delete[](void*) throw();
class FEPoseAnimation_e8730 {
  public:
    void* vptr;
    char* m4;
    char p[4];
    Ref_e8730* mc;
    char p2[0x50];
    Ref_e8730* m60;
    ~FEPoseAnimation_e8730() throw();
};
FEPoseAnimation_e8730::~FEPoseAnimation_e8730() throw() {
    vptr = DAT_0040c390;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    vptr = DAT_0040bfc0;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m4) {
        operator delete[](m4);
        m4 = 0;
    }
}
