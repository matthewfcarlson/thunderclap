// Same code shape as 0x0002e6d0 (propagated; names are from that function)
class CActorManager {
  public:
    void Method(const char*, float);
};
struct Pair_1bfdf0 {
    const char* s;
    float f;
};
class Closure2 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, Pair_1bfdf0*, void*);
    char pad[0x1c - 4];
    void (CActorManager::*mFn)(const char*, float);
    CActorManager* mObj;
};
void Closure2::vfunc_2(void* a, Pair_1bfdf0* p, void* c) {
    (mObj->*mFn)(p->s, p->f);
}
