struct Function {
    virtual void f0();
    virtual void f1();
};
struct Dummy {
    int x;
};
typedef bool (Dummy::*Fn)(bool);
struct Method1 : Function {
    char pad[0x18];
    Fn fn;
    virtual void f0();
    virtual void f2(void* a, bool* b, bool* out);
};
void Method1::f2(void* a, bool* b, bool* out) {
    Fn f = fn;
    bool bv = *b;
    bool v = (((Dummy*)a)->*f)(bv);
    if (out)
        *out = v;
}
