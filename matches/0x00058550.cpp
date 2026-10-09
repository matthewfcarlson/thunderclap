typedef unsigned int u32;
void* __cdecl Allocate(unsigned int);
struct CMotionStateCondition {
    u32 vtable;
    u32 pad4;
    u32 pad8;
    u32 fieldC;
    u32 field10;
    void Initialize(int);
};
struct ConditionFactoryTemplate {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* ConditionFactoryTemplate::vfunc_5() {
    CMotionStateCondition* p = (CMotionStateCondition*)Allocate(0x14);
    if (p) {
        p->Initialize(0);
        p->vtable = 0x3f7394;
        p->fieldC = 0;
        p->field10 = 1;
        return p;
    } else {
        return 0;
    }
}
