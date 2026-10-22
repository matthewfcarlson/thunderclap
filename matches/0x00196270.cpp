extern "C" void _ReadWriteBarrier();
extern void* g_vftable_196270[];
extern void* g_vftable2[];
class Ref_196270 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_196270 {
  public:
    void* vptr;
    void Fin();
};

class FireMissileAction_196270 : public Action_196270 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_196270* m20;
    ~FireMissileAction_196270();
};
FireMissileAction_196270::~FireMissileAction_196270() {
    vptr = g_vftable_196270;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
