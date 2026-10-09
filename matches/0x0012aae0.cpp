typedef unsigned int u32;
typedef unsigned char u8;
struct AcquireTargetCondition {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad4[8];
    float a;
    float b;
    u8 c;
    void Initialize(int);
};
void* __cdecl alloc(unsigned int);
struct Factory {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    AcquireTargetCondition* make();
};
AcquireTargetCondition* Factory::make() {
    AcquireTargetCondition* p = (AcquireTargetCondition*)alloc(0x18);
    if (p) {
        p->Initialize(0);
        *(u32*)p = 0x40feb4;
        p->a = 1.57079637f;
        p->b = 100.0f;
        p->c = 1;
        return p;
    }
    return 0;
}