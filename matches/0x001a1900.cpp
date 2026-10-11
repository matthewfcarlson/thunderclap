extern "C" void _ReadWriteBarrier();
class Thing {
  public:
    virtual void A();
    virtual void Release();
};
class Base {
  public:
    virtual ~Base() throw();
};
class LuaAction : public Base {
  public:
    char pad[0x1c];
    Thing* mThing;
    virtual ~LuaAction() throw();
};
LuaAction::~LuaAction() throw() {
    *(void**)this = (void*)0x41c390;
    _ReadWriteBarrier();
    if (mThing) {
        mThing->Release();
        mThing = 0;
    }
}