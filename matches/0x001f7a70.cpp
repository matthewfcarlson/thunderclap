class CEffectManager {
  public:
    unsigned int run(unsigned int);
};
struct Arg {
    unsigned int v;
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    typedef unsigned int (CEffectManager::*Fn)(unsigned int);
    Fn fn;
    virtual void f2(CEffectManager*, Arg*, unsigned int*);
};
inline unsigned int invoke(CEffectManager* obj, Method1::Fn f, unsigned int v) {
    return (obj->*f)(v);
}
void Method1::f2(CEffectManager* obj, Arg* arg, unsigned int* out) {
    Fn f = fn;
    unsigned int value = invoke(obj, f, arg->v);
    if (out)
        *out = value;
}