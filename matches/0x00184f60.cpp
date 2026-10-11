extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void A();
    virtual void B();
};
class Base {
  public:
    void Finish();
};
class BallAndChainReturnAction {
  public:
    volatile int vptr;
    char pad[0x18];
    void* mOne;
    Ref* mTwo;
    void Reset();
};
void BallAndChainReturnAction::Reset() {
    vptr = 0x4197c8;
    _ReadWriteBarrier();
    if (mTwo) {
        mTwo->B();
        mTwo = 0;
    }
    if (mOne)
        mOne = 0;
    ((Base*)this)->Finish();
}