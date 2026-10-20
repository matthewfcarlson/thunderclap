extern "C" void _ReadWriteBarrier();
extern void* g_vftable_173340[];
class Ref_173340 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_173340 {
  public:
    void* vptr;
    void Fin();
};
class LocomotionStateAction_173340 : public Base_173340 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_173340* m20;
    ~LocomotionStateAction_173340();
};
LocomotionStateAction_173340::~LocomotionStateAction_173340() {
    vptr = g_vftable_173340;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
