extern "C" void _ReadWriteBarrier();
extern void* g_vftable_e9030[];
class Ref_e9030 {
  public:
    virtual void F0();
    virtual void Release();
};
void operator delete[](void*) throw();
struct Sub_e9030 {
    char c;
    void Fin() throw();
};
class FEObject_e9030 {
  public:
    void* vptr;
    char p[0x14];
    Sub_e9030 s18;
    char p2[0x37];
    Ref_e9030* m50;
    char p3[0xc];
    Ref_e9030* m60;
    Ref_e9030* m64;
    char p4[0x44];
    char* mac;
    ~FEObject_e9030() throw();
};
FEObject_e9030::~FEObject_e9030() throw() {
    vptr = g_vftable_e9030;
    _ReadWriteBarrier();
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (mac) {
        operator delete[](mac);
        mac = 0;
    }
    s18.Fin();
}
