extern "C" void _ReadWriteBarrier();
extern void* g_vftable_176fa0[];
class Ref_176fa0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_176fa0 {
  public:
    void* vptr;
    void Fin();
};
class RestPoseAction_176fa0 : public Base_176fa0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_176fa0* m20;
    Ref_176fa0* m24;
    ~RestPoseAction_176fa0();
};
RestPoseAction_176fa0::~RestPoseAction_176fa0() {
    vptr = g_vftable_176fa0;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
