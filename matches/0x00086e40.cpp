class Function {
  public:
    virtual void a();
    virtual void b();
};
typedef float(__cdecl* Fn_86e40)();
class Function0 : public Function {
  public:
    virtual void a();
    virtual void b();
    virtual void f2(void*, void*, float*);
    char pad[0x18];
    Fn_86e40 mFn;
};
void Function0::f2(void*, void*, float* out) {
    Fn_86e40 fn = mFn;
    float v = fn();
    if (out)
        *out = v;
}