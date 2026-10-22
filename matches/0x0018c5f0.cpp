extern "C" void* __cdecl operator_new(unsigned int);
inline void* operator new(unsigned int, void* where) {
    return where;
}
struct Condition_18c5f0 {
    virtual void f0();
    Condition_18c5f0(int);
    char pad[8];
};
struct Sub_18c5f0 {
    Sub_18c5f0();
    char pad[8];
};
struct PropMassCondition_18c5f0 : Condition_18c5f0 {
    PropMassCondition_18c5f0() : Condition_18c5f0(0), a(0), b(0), s(), mass(1.0f) {}
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
PropMassCondition_18c5f0* factory_vfunc_5() {
    PropMassCondition_18c5f0* p = (PropMassCondition_18c5f0*)operator_new(0x28);
    if (p) {
        p = new (p) PropMassCondition_18c5f0();
    } else
        p = 0;
    return p;
}
