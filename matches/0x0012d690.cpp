extern "C" char DAT_00410bf4[];
typedef unsigned int u32_12d690;
extern void* Alloc(unsigned int);
struct Sub_12d690 {
    void Setup();
};
struct ThreatDistanceCondition {
    u32_12d690 vf;
    char pad04[8];
    u32_12d690 mC;
    u32_12d690 mD;
    char pad14[4];
    Sub_12d690 sub;
    char pad1c[7];
    char flag;
    void Init(int);
};
struct Factory_12d690 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* Factory_12d690::vfunc_5() {
    ThreatDistanceCondition* p = (ThreatDistanceCondition*)Alloc(0x28);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_00410bf4);
        p->mC = 0;
        p->mD = 0;
        p->sub.Setup();
        p->flag = 1;
        return p;
    }
    return 0;
}