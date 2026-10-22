extern "C" void _ReadWriteBarrier();
extern void* g_vftable_e8730[];
extern void* g_vftable2[];
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
    vptr = g_vftable_e8730;
    _ReadWriteBarrier();
    if (mc) {
        mc->Release();
        mc = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    vptr = g_vftable2;
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
