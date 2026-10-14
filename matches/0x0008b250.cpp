// Same code shape as 0x0002fe60 (propagated; names are from that function)
class CActorManager {
  public:
    float Get();
};
typedef float (CActorManager::*Fn_8b250)();
class Closure0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int a, int b, float* out);
    char pad[0x18];
    Fn_8b250 mFn;
    CActorManager* mMgr;
};
void Closure0::vfunc_2(int a, int b, float* out) {
    CActorManager* m = mMgr;
    Fn_8b250 fn = mFn;
    float v = (m->*fn)();
    if (out)
        *out = v;
}
