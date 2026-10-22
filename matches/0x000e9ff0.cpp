extern "C" void _ReadWriteBarrier();
extern void* g_vftable_e9ff0[];
extern void* g_vftable2[];
class Ref_e9ff0 {
  public:
    virtual void F0();
    virtual void Release();
};
void operator delete[](void*) throw();
struct Mgr_e9ff0 {
    void Rem(void* p) throw();
};
struct Own_e9ff0 {
    char p[8];
    Mgr_e9ff0* m8;
};
struct Sub_e9ff0 {
    char c;
    void Fin() throw();
};
class HSlider_e9ff0 {
  public:
    void* vptr;
    char p[0x14];
    Sub_e9ff0 s18;
    char p2[0x37];
    Ref_e9ff0* m50;
    char p3[0xc];
    Ref_e9ff0* m60;
    Ref_e9ff0* m64;
    char p4[0x40];
    Own_e9ff0* ma8;
    char* mac;
    char p5[0xd0];
    char* m180;
    char p6[0xc];
    Ref_e9ff0* m190;
    Ref_e9ff0* a[10];
    Ref_e9ff0* b[10];
    ~HSlider_e9ff0() throw();
};
HSlider_e9ff0::~HSlider_e9ff0() throw() {
    vptr = g_vftable_e9ff0;
    if (m180)
        ma8->m8->Rem(m180 + 0x18);
    if (m190)
        m190->Release();
    for (int i = 0; i < 10; i++)
        if (a[i])
            a[i]->Release();
    for (int i = 0; i < 10; i++)
        if (b[i])
            b[i]->Release();
    vptr = g_vftable2;
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
