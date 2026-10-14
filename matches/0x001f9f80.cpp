struct Sub_1f9f80 {
    void Helper();
};
struct Obj_1f9f80 {
    char pad[16];
    Sub_1f9f80 sub;
};
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(void*);
};
struct B_1f9f80 {
    char pad[0x18];
    V* p;
};
bool Target(Obj_1f9f80* a, B_1f9f80* b) {
    a->sub.Helper();
    b->p->f4(a);
    return true;
}