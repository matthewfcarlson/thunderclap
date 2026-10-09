class Function {
  public:
    virtual void a();
    virtual void b();
};
typedef float(__cdecl* Fn)();
class Function0 : public Function {
  public:
    virtual void a();
    virtual void b();
    virtual void f2(void*, void*, float*);
    char pad[0x18];
    Fn mFn;
};
void Function0::f2(void*, void*, float* out) {
    Fn fn = mFn;
    float v = fn();
    if (out)
        *out = v;
}