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
    vptr = (char*)0x417fd4;
    _ReadWriteBarrier();
    if (ref) {
        ref->B();
        ref = 0;
    }
    Tail();
}