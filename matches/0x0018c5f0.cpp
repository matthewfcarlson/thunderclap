extern "C" void* __cdecl operator_new(unsigned int);
inline void* operator new(unsigned int, void* where) {
    return where;
}
struct Base_18c5f0 {
    virtual void f0();
    Base_18c5f0(int);
    char pad[8];
};
struct Sub_18c5f0 {
    Sub_18c5f0();
    char pad[8];
};
struct PMC : Base_18c5f0 {
    PMC() : Base_18c5f0(0), a(0), b(0), s(), mass(1.0f) {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    int a;
    int b;
    char gap[4];
    Sub_18c5f0 s;
    float mass;
};
PMC* factory_vfunc_5() {
    PMC* p = (PMC*)operator_new(0x28);
    if (p) {
        p = new (p) PMC();
    } else
        p = 0;
    return p;
}
