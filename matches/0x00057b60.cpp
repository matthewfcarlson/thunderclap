extern "C" char DAT_003f70a0[];
void* __cdecl Allocate(unsigned int);
struct CCollisionPushbackYCondition {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    int pad0;
    int pad1;
    int a;
    int b;
};
struct Initializer_57b60 {
    void init(int);
};
struct Factory_57b60 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CCollisionPushbackYCondition* vfunc_5();
};
CCollisionPushbackYCondition* Factory_57b60::vfunc_5() {
    CCollisionPushbackYCondition* p = (CCollisionPushbackYCondition*)Allocate(0x14);
    if (p) {
        ((Initializer_57b60*)p)->init(0);
        *(unsigned int*)p = ((int)DAT_003f70a0);
        p->a = 3;
        p->b = 0;
    } else
        return (CCollisionPushbackYCondition*)0;
    return p;
}