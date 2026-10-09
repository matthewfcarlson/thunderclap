typedef unsigned int U;
struct Part {
    void f5d30();
};
struct Sub {
    U f75e0(U);
    void f7550(U);
};
struct Obj {
    char pad[0x128];
    void target(U arg);
};
extern void __cdecl thunk(U);
void Obj::target(U arg) {
    Sub* sub = (Sub*)((char*)this + 0x128);
    U r = sub->f75e0(arg);
    sub->f7550(arg);
    if (r) {
        ((Part*)r)->f5d30();
        thunk(r);
    }
}
