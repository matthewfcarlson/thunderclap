typedef unsigned char u8;
class Callback_e1930 {
  public:
    virtual void a();
    virtual void b();
};
extern "C" float(__cdecl* GetDelta)();
class FEDoAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class FEDoWait : public FEDoAction {
  public:
    char pad[0x34 - sizeof(FEDoAction)];
    float limit;
    float elapsed;
    Callback_e1930* callback;
    u8 done;
    void vfunc_2();
};
void FEDoWait::vfunc_2() {
    if (!done) {
        if (elapsed >= limit) {
            done = 1;
            if (!callback)
                return;
            callback->b();
        }
        elapsed += GetDelta();
    }
}