extern "C" char DAT_00410bf4[];
typedef unsigned int u32;
extern void* Alloc(unsigned int);
struct Sub {
    void Setup();
};
struct ThreatDistanceCondition {
    u32 vf;
    char pad04[8];
    u32 mC;
    u32 mD;
    char pad14[4];
    Sub sub;
    char pad1c[7];
    char flag;
    void Init(int);
};
struct Factory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* vfunc_5();
};
void* Factory::vfunc_5() {
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