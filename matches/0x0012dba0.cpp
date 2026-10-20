#include "compat/ptr.h"
extern "C" char DAT_00411110[];
extern "C" void _ReadWriteBarrier();
class Ref_12dba0 {
  public:
    virtual void f();
    virtual void Release();
};
class Base_12dba0 {
  public:
    virtual void Dummy();
    void Finish();
};
class PostEvent_StringAction : public Base_12dba0 {
  public:
    void Clean();
    char pad0[0x20 - 4];
    Ref_12dba0* mRef;
};
void PostEvent_StringAction::Clean() {
    *(void**)this = (void*)((hulk_intptr)DAT_00411110);
    _ReadWriteBarrier();
    if (mRef) {
        mRef->Release();
        mRef = 0;
    }
    Finish();
}
