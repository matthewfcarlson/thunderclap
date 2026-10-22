extern "C" void _ReadWriteBarrier();
extern void* g_vftable_a0d80[];
class Ref_a0d80 {
  public:
    virtual void F0();
    virtual void Release();
};
class CGameCamera_a0d80 {
  public:
    void* vptr;
    void Fin();
    void Fin29();
};
class CChaseCamera_a0d80 : public CGameCamera_a0d80 {
  public:
    char pad[0x350 - 4];
    Ref_a0d80* m350;
    ~CChaseCamera_a0d80();
};
CChaseCamera_a0d80::~CChaseCamera_a0d80() {
    vptr = g_vftable_a0d80;
    _ReadWriteBarrier();
    if (m350) {
        m350->Release();
        m350 = 0;
    }
    Fin29();
    Fin();
}
