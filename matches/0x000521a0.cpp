struct CFightNodeTimeCondition { virtual ~CFightNodeTimeCondition(); char pad[0x10]; void Initialize(); };
extern void* __cdecl operator_new(unsigned int);
extern void* conditionVtable;
struct Factory { virtual void* a(); virtual void* b(); virtual void* c(); virtual void* d(); virtual void* e(); virtual CFightNodeTimeCondition* vfunc_5(); };
CFightNodeTimeCondition* Factory::vfunc_5() {
    CFightNodeTimeCondition* p = (CFightNodeTimeCondition*)operator_new(0x14);
    if (p) { p->Initialize(); *(void**)p = &conditionVtable; return p; }
    return 0;
}