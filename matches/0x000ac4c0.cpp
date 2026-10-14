extern "C" void _ReadWriteBarrier();
extern void* g_vftable_ac4c0[];
class Ref_ac4c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_ac4c0 {
  public:
    void* vptr;
    void Fin();
};
class Cam_ac4c0 : public Base_ac4c0 {
  public:
    char pad[0x170 - 4];
    Ref_ac4c0* m170;
    ~Cam_ac4c0();
};
Cam_ac4c0::~Cam_ac4c0() {
    vptr = g_vftable_ac4c0;
    _ReadWriteBarrier();
    if (m170) {
        m170->Release();
        m170 = 0;
    }
    Fin();
}
