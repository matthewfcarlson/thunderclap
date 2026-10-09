class CActorManager;
typedef bool(__fastcall* Fn)(CActorManager*);
class Closure0ActorBool {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, void*, bool* out);
    char pad[0x1c - 4];
    Fn mFn;
    CActorManager* mObj;
};
void Closure0ActorBool::f2(void*, void*, bool* out) {
    CActorManager* o = mObj;
    Fn fn = mFn;
    bool b = fn(o);
    if (out)
        *out = b;
}
