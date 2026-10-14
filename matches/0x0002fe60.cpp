class CActorManager {
  public:
    float Get();
};
typedef float (CActorManager::*Fn_2fe60)();
class Closure0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int a, int b, float* out);
    char pad[0x18];
    Fn_2fe60 mFn;
    CActorManager* mMgr;
};
void Closure0::vfunc_2(int a, int b, float* out) {
    CActorManager* m = mMgr;
    Fn_2fe60 fn = mFn;
    float v = (m->*fn)();
    if (out)
        *out = v;
}
