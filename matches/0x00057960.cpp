extern "C" char DAT_003f7034[];
typedef unsigned int u32_57960;
struct CCollisionInterruptCondition {
    u32_57960 vf;
    char pad[8];
    unsigned char flag;
};
extern void* __cdecl allocate(unsigned int);
struct Initializer_57960 {
    void init(int);
};
class ConditionFactoryTemplate {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual CCollisionInterruptCondition* vfunc_5();
};
CCollisionInterruptCondition* ConditionFactoryTemplate::vfunc_5() {
    CCollisionInterruptCondition* p = (CCollisionInterruptCondition*)allocate(0x10);
    if (p) {
        ((Initializer_57960*)p)->init(0);
        p->vf = ((int)DAT_003f7034);
        p->flag = 1;
        return p;
    }
    return (CCollisionInterruptCondition*)0;
}