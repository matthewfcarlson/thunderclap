extern "C" void _ReadWriteBarrier();
extern void* g_vftable_126860[];
class Ref_126860 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_126860 {
  public:
    void* vptr;
    void Fin();
};
class ClearProjectileDistanceAction_126860 : public Action_126860 {
  public:
    char pad[0x18];
    void* m1c;
    Ref_126860* m20;
    ~ClearProjectileDistanceAction_126860();
};
ClearProjectileDistanceAction_126860::~ClearProjectileDistanceAction_126860() {
    vptr = g_vftable_126860;
    _ReadWriteBarrier();
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
