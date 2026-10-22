extern "C" void _ReadWriteBarrier();
extern void* g_vftable_e86f0[];
void operator delete(void*);
void operator delete[](void*);
class Ref_e86f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEAnimation_e86f0 {
  public:
    void* vptr;
    void* m4;
    int m8;
    Ref_e86f0* mc;
    ~FEAnimation_e86f0();
};
FEAnimation_e86f0::~FEAnimation_e86f0() {
    vptr = g_vftable_e86f0;
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
