#include "compat/ptr.h"
extern "C" char DAT_00417fd4[];
extern "C" void _ReadWriteBarrier();
class Ref_176510 {
  public:
    virtual void A();
    virtual void B();
};
class Action_176510 {
  public:
    void Tail();
};
class TargetBreakAction : public Action_176510 {
  public:
    void Finish();
    char* vptr;
    char pad[0x18];
    Ref_176510* ref;
};
void TargetBreakAction::Finish() {
    vptr = (char*)((hulk_intptr)DAT_00417fd4);
    _ReadWriteBarrier();
    if (ref) {
        ref->B();
        ref = 0;
    }
    Tail();
}