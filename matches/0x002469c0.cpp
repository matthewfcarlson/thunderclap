struct V {
    virtual void a();
    virtual void b();
};
struct X {
    void** vptr;
    char pad[0x18];
    V* m;
    void f();
};
void X::f() {
    vptr = (void**)0x429214;
    m->b();
    vptr = (void**)0x423f20;
}