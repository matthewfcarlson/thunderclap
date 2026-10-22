extern "C" void _ReadWriteBarrier();
extern char vtable_190a00[];
class Obj_190a00 {
  public:
    virtual void A();
    virtual void B();
};
class TankLocomotionAction_190a00 {
  public:
    void Finish();
};
class ImpulseVelocityAction {
  public:
    char pad[0x1c];
    void* m1c;
    Obj_190a00* m20;
    void Cleanup();
};
void ImpulseVelocityAction::Cleanup() {
    *(void**)this = &vtable_190a00;
    _ReadWriteBarrier();
    if (m20) {
        m20->B();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((TankLocomotionAction_190a00*)this)->Finish();
}