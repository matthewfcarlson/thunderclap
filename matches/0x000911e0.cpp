// Same code shape as 0x0002f6a0 (propagated; names are from that function)
class CActorManager;
typedef bool(__fastcall* Fn_911e0)(CActorManager*);
class Closure0ActorBool_911e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*, bool* out);
    char pad[0x1c - 4];
    Fn_911e0 mFn;
    CActorManager* mObj;
};
void Closure0ActorBool_911e0::f2(void*, void*, bool* out) {
    CActorManager* o = mObj;
    Fn_911e0 fn = mFn;
    bool b = fn(o);
    if (out)
        *out = b;
}
