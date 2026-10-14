extern "C" char DAT_00428210[];
extern "C" void* __cdecl alloc(unsigned int);
struct RandomCondition {
    int vf;
    int pad[2];
    int value;
    void Init(int);
};
struct Factory_2387f0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual RandomCondition* vfunc_5();
};
RandomCondition* Factory_2387f0::vfunc_5() {
    RandomCondition* p = (RandomCondition*)alloc(0x10);
    if (p) {
        p->Init(0);
        p->vf = ((int)DAT_00428210);
        p->value = 0;
    } else {
        p = 0;
    }
    return p;
}