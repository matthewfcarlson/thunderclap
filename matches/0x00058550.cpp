extern "C" char DAT_003f7394[];
typedef unsigned int u32_58550;
void* __cdecl Allocate(unsigned int);
struct CMotionStateCondition {
    u32_58550 vtable;
    u32_58550 pad4;
    u32_58550 pad8;
    u32_58550 fieldC;
    u32_58550 field10;
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
        p->vtable = ((int)DAT_003f7394);
        p->fieldC = 0;
        p->field10 = 1;
        return p;
    } else {
        return 0;
    }
}
