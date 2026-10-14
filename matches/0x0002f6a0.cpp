class CActorManager;
typedef bool(__fastcall* Fn_2f6a0)(CActorManager*);
class Closure0ActorBool_2f6a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*, bool* out);
    char pad[0x1c - 4];
    Fn_2f6a0 mFn;
    CActorManager* mObj;
};
void Closure0ActorBool_2f6a0::f2(void*, void*, bool* out) {
    CActorManager* o = mObj;
    Fn_2f6a0 fn = mFn;
    bool b = fn(o);
    if (out)
        *out = b;
}
