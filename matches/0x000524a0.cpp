// Same code shape as 0x000521a0 (propagated; names are from that function)
struct CFightNodeTimeCondition {
    virtual ~CFightNodeTimeCondition();
    char pad[0x10];
    void Initialize();
};
extern void* __cdecl operator_new(unsigned int);
extern void* conditionVtable;
struct Factory_524a0 {
    virtual void* a();
    virtual void* b();
    virtual void* c();
    virtual void* d();
    virtual void* e();
    virtual CFightNodeTimeCondition* vfunc_5();
};
CFightNodeTimeCondition* Factory_524a0::vfunc_5() {
    CFightNodeTimeCondition* p = (CFightNodeTimeCondition*)operator_new(0x14);
    if (p) {
        p->Initialize();
        *(void**)p = &conditionVtable;
        return p;
    }
    return 0;
}