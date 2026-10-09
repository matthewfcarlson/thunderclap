typedef unsigned int u32;
extern void* __cdecl Alloc(unsigned int);
struct CCollisionDirectionCondition {
    u32 vptr;
    u32 pad4, pad8, fieldC, field10;
    void Init(int);
};
class Factory { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual CCollisionDirectionCondition* vfunc_5(); };
CCollisionDirectionCondition* Factory::vfunc_5() {
    CCollisionDirectionCondition* p = (CCollisionDirectionCondition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = 0x3f6fc8;
        p->fieldC = 0;
        p->field10 = 0x3fc90fdb;
        return p;
    }
    return 0;
}
