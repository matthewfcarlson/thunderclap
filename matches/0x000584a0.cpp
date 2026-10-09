extern "C" void* __cdecl Allocate(unsigned int);
struct CMotionHitCondition {
    unsigned int vtable;
    unsigned int pad1;
    unsigned int pad2;
    unsigned int value;
    unsigned int value2;
    void Init(int);
};
struct Factory {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
void* Factory::vfunc_5() {
    CMotionHitCondition* p = (CMotionHitCondition*)Allocate(0x14);
    if (p) {
        p->Init(0);
        p->vtable = 0x3f73bc;
        p->value = 0;
        p->value2 = 2;
        return p;
    }
    return 0;
}