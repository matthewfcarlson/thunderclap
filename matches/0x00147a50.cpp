typedef unsigned char u8;
struct P_147a50 {
    P_147a50* A();
    P_147a50* B();
    int C();
};
extern int __cdecl TypeCheck(void* a, int b, void* c, void* d, int e);
extern char kDesc1;
extern char kDesc2;
struct CivilianAttachedCondition {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(void* a, void* b, void* c);
    char pad[8];
    u8 flag;
};
bool CivilianAttachedCondition::vfunc_6(void* a, void* b, void* c) {
    if (!TypeCheck(b, 0, &kDesc1, &kDesc2, 0))
        return false;
    P_147a50* p = ((P_147a50*)b)->A();
    p = p->B();
    int x = p->C();
    bool r = (x != 0);
    return r == flag;
}
