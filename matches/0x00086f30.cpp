typedef const char*(__cdecl* Fn_86f30)(const char*);
struct Function {
    virtual void f0();
    virtual void f1();
};
struct Function1 : Function {
    char pad[0x1c - sizeof(Function)];
    Fn_86f30 mFn;
    virtual void f0();
    virtual void f1();
    virtual void f2(void*, const char**, const char**);
};
void Function1::f2(void*, const char** arg, const char** out) {
    const char* a = *arg;
    Fn_86f30 fn = mFn;
    const char* result = fn(a);
    if (out)
        *out = result;
}