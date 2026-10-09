class CActorManager {
  public:
    float Get();
};
typedef float (CActorManager::*Fn)();
class Closure0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int a, int b, float* out);
    char pad[0x18];
    Fn mFn;
    CActorManager* mMgr;
};
void Closure0::vfunc_2(int a, int b, float* out) {
    CActorManager* m = mMgr;
    Fn fn = mFn;
    float v = (m->*fn)();
    if (out)
        *out = v;
}
