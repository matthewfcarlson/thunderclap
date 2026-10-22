extern "C" void _ReadWriteBarrier();
extern void* g_vftable_832b0[];
class Ref_832b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_832b0 {
  public:
    void* vptr;
    void Fin();
};
class CCow_832b0 : public Entity_832b0 {
  public:
    char pad[0x3c - 4];
    Ref_832b0* m3c;
    ~CCow_832b0();
};
CCow_832b0::~CCow_832b0() {
    vptr = g_vftable_832b0;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    Fin();
}
