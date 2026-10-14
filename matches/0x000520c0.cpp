extern "C" char DAT_003f8504[];
typedef unsigned int u32_520c0;
struct CFightNodeParentCondition {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    void InitMe();
};
void* __cdecl Allocate(unsigned int);
struct Factory_520c0 {
    CFightNodeParentCondition* vfunc_5();
};
CFightNodeParentCondition* Factory_520c0::vfunc_5() {
    CFightNodeParentCondition* p = (CFightNodeParentCondition*)Allocate(0x20);
    if (p) {
        p->InitMe();
        *(u32_520c0*)p = ((int)DAT_003f8504);
        return p;
    }
    return 0;
}