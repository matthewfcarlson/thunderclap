struct CIsGrappledCondition {
    virtual ~CIsGrappledCondition();
    void init(int);
};
void* operator new(unsigned int);
extern void* condition_vftable_52580;
struct Factory_52580 {
    void* vfunc0();
    void* vfunc1();
    void* vfunc2();
    void* vfunc3();
    void* vfunc4();
    void* vfunc5();
};
void* Factory_52580::vfunc5() {
    CIsGrappledCondition* p = (CIsGrappledCondition*)operator new(0x0c);
    if (p) {
        p->init(0);
        *(void**)p = &condition_vftable_52580;
        return p;
    }
    return 0;
}