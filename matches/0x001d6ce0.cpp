struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
struct A_1d6ce0 {
    bool run();
};
struct B_1d6ce0 {
    bool run();
};
struct G_1d6ce0 {
    char pad[8];
    B_1d6ce0* p;
};
extern G_1d6ce0* g_4dd700;
struct CSPHulkPropInstance {
    char x[0x9c];
    V* obj;
    char pad[0x4c];
    A_1d6ce0* a;
    void vfunc_8(int, int);
};
void CSPHulkPropInstance::vfunc_8(int x, int y) {
    if (a->run() && g_4dd700->p->run())
        return;
    obj->f8(x, y);
}