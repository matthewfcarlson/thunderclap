extern "C" char DAT_003f7528[];
typedef unsigned int u32_576a0;
extern "C" void* __cdecl Alloc(unsigned int);
struct CClimbEdgeCondition {
    u32_576a0 vptr;
    char pad[8];
    u32_576a0 f0c;
    char f10;
    void Init(int);
};
class Factory_576a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CClimbEdgeCondition* vfunc_5();
};
CClimbEdgeCondition* Factory_576a0::vfunc_5() {
    CClimbEdgeCondition* p = (CClimbEdgeCondition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = ((int)DAT_003f7528);
        p->f0c = 0;
        p->f10 = 0;
        return p;
    }
    return 0;
}
