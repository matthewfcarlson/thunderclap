// Same code shape as 0x0002ee10 (propagated; names are from that function)
class CActorManager {
  public:
    int act();
};
class Closure0 {
  public:
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2(int, int, int*);
    char pad[0x1c - 4];
    int (CActorManager::*mFn)();
    CActorManager* mThis;
};
void Closure0::f2(int, int, int* out) {
    CActorManager* obj = mThis;
    int (CActorManager::*fn)() = mFn;
    int result = (obj->*fn)();
    if (out)
        *out = result;
}
