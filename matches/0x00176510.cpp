extern "C" char DAT_00417fd4[];
extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    void Tail();
};
class TargetBreakAction : public Base {
  public:
    void Finish();
    char* vptr;
    char pad[0x18];
    Ref* ref;
};
void TargetBreakAction::Finish() {
    vptr = (char*)((int)DAT_00417fd4);
    _ReadWriteBarrier();
    if (ref) {
        ref->B();
        ref = 0;
    }
    Tail();
}