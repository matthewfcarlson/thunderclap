extern "C" void _ReadWriteBarrier();
extern char vtable[];
class Obj {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    void Finish();
};
class ImpulseVelocityAction {
  public:
    char pad[0x1c];
    void* m1c;
    Obj* m20;
    void Cleanup();
};
void ImpulseVelocityAction::Cleanup() {
    *(void**)this = &vtable;
    _ReadWriteBarrier();
    if (m20) {
        m20->B();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((Base*)this)->Finish();
}