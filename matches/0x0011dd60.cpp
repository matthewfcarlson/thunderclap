extern "C" void _ReadWriteBarrier();
extern void* g_vftable_11dd60[];
class Ref_11dd60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_11dd60 {
  public:
    void* vptr;
    void Fin();
};
class StrafeCircleHBAction_11dd60 : public Action_11dd60 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_11dd60* m20;
    Ref_11dd60* m24;
    ~StrafeCircleHBAction_11dd60();
};
StrafeCircleHBAction_11dd60::~StrafeCircleHBAction_11dd60() {
    vptr = g_vftable_11dd60;
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
