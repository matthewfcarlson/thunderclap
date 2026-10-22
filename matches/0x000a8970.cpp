extern "C" void _ReadWriteBarrier();
extern void* g_vftable_a8970[];
class Ref_a8970 {
  public:
    virtual void F0();
    virtual void Release();
};
class CGameCamera_a8970 {
  public:
    void* vptr;
    void Fin();
};
class CDramaticCamera_a8970 : public CGameCamera_a8970 {
  public:
    char pad[0x170 - 4];
    Ref_a8970* m170;
    Ref_a8970* m174;
    ~CDramaticCamera_a8970();
};
CDramaticCamera_a8970::~CDramaticCamera_a8970() {
    vptr = g_vftable_a8970;
    _ReadWriteBarrier();
    if (m170) {
        m170->Release();
        m170 = 0;
    }
    if (m174) {
        m174->Release();
        m174 = 0;
    }
    Fin();
}
