class CHand2HandAgent {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    char pad0[0x8c-4]; float a; char pad1[0xa8-0x90]; float b;
    virtual bool vfunc_18(float);
};
bool CHand2HandAgent::vfunc_18(float limit) {
    float d = a - b;
    union { float f; unsigned int i; } u;
    u.f = d;
    u.i &= 0x7fffffff;
    return u.f < limit;
}