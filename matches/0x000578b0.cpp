typedef unsigned int u32;
extern void* __cdecl FUN_0008d690(unsigned int);
struct CCollisionHitLocationCondition {
    virtual void a();
    virtual void b();
    virtual void c();
    int pad;
    int x;
    void Init(int);
};
struct Factory {
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual void* v3();
    virtual void* v4();
    CCollisionHitLocationCondition* vfunc_5();
};
CCollisionHitLocationCondition* Factory::vfunc_5() {
    CCollisionHitLocationCondition* p = (CCollisionHitLocationCondition*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(u32*)p = 0x3f6fa4;
        ((u32*)p)[3] = 2;
        ((u32*)p)[4] = 1;
        return p;
    }
    return 0;
}