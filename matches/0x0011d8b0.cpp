extern "C" void _ReadWriteBarrier();
extern void* g_vftable_11d8b0[];
extern void* g_vftable2[];
class Ref_11d8b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_11d8b0 {
  public:
    void* vptr;
    void Fin();
};

class StrafeCircleAction_11d8b0 : public Action_11d8b0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_11d8b0* m20;
    Ref_11d8b0* m24;
    ~StrafeCircleAction_11d8b0();
};
StrafeCircleAction_11d8b0::~StrafeCircleAction_11d8b0() {
    vptr = g_vftable_11d8b0;
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
