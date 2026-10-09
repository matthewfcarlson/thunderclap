// Same code shape as 0x00052580 (propagated; names are from that function)
struct CIsGrappledCondition {
    virtual ~CIsGrappledCondition();
    void init(int);
};
void* operator new(unsigned int);
extern void* condition_vftable;
struct Factory {
    void* vfunc0();
    void* vfunc1();
    void* vfunc2();
    void* vfunc3();
    void* vfunc4();
    void* vfunc5();
};
void* Factory::vfunc5() {
    CIsGrappledCondition* p = (CIsGrappledCondition*)operator new(0x0c);
    if (p) {
        p->init(0);
        *(void**)p = &condition_vftable;
        return p;
    }
    return 0;
}