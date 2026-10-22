extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1390c0[];
void operator delete(void*);
class Ref_1390c0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1390c0 {
  public:
    void* vptr;
    void Fin();
};
class AirToGroundTargetAction_1390c0 : public Action_1390c0 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_1390c0* m20;
    Ref_1390c0* m24;
    Ref_1390c0* m28;
    AirToGroundTargetAction_1390c0* f2(unsigned char flags);
};
AirToGroundTargetAction_1390c0* AirToGroundTargetAction_1390c0::f2(unsigned char flags) {
    vptr = g_vftable_1390c0;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
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
    if (flags & 1)
        operator delete(this);
    return this;
}
