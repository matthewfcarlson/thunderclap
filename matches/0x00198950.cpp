extern "C" void _ReadWriteBarrier();
extern void* g_vftable_198950[];
class Ref_198950 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_198950 {
  public:
    void* vptr;
    void Fin();
};
class FireGroundShockwaveAction_198950 : public Action_198950 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_198950* m20;
    ~FireGroundShockwaveAction_198950();
};
FireGroundShockwaveAction_198950::~FireGroundShockwaveAction_198950() {
    vptr = g_vftable_198950;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
