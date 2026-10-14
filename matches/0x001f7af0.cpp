struct Function {
    virtual void f0();
    virtual void f1();
};
struct Dummy_1f7af0 {
    int x;
};
typedef bool (Dummy_1f7af0::*Fn_1f7af0)(bool);
struct Method1 : Function {
    char pad[0x18];
    Fn_1f7af0 fn;
    virtual void f0();
    virtual void f2(void* a, bool* b, bool* out);
};
void Method1::f2(void* a, bool* b, bool* out) {
    Fn_1f7af0 f = fn;
    bool bv = *b;
    bool v = (((Dummy_1f7af0*)a)->*f)(bv);
    if (out)
        *out = v;
}
