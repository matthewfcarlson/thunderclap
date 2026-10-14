// Same code shape as 0x0002d750 (propagated; names are from that function)
class CActorManager;
typedef bool(__fastcall* Fn_1bf670)(CActorManager*);
class Method0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(CActorManager* obj, void* a, unsigned char* out);
    char pad[0x18];
    Fn_1bf670 mFn;
};
void Method0::f2(CActorManager* obj, void* a, unsigned char* out) {
    Fn_1bf670 fn = mFn;
    bool r = fn(obj);
    if (out)
        *out = r;
}
