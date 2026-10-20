#include "compat/ptr.h"
extern "C" char DAT_0041c390[];
extern "C" void _ReadWriteBarrier();
class Thing_1a1900 {
  public:
    virtual void A();
    virtual void Release();
};
class Base_1a1900 {
  public:
    virtual ~Base_1a1900() throw();
};
class LuaAction : public Base_1a1900 {
  public:
    char pad[0x1c];
    Thing_1a1900* mThing;
    virtual ~LuaAction() throw();
};
LuaAction::~LuaAction() throw() {
    *(void**)this = (void*)((hulk_intptr)DAT_0041c390);
    _ReadWriteBarrier();
    if (mThing) {
        mThing->Release();
        mThing = 0;
    }
}