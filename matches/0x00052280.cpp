// Same code shape as 0x00051fe0 (propagated; names are from that function)
void* __cdecl Allocate(unsigned int);
extern void* CFightNodeConditionVtable;
struct CFightNodeCondition { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); void Init(); };
struct Factory { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual CFightNodeCondition* vfunc_5(); };
CFightNodeCondition* Factory::vfunc_5() { CFightNodeCondition* p=(CFightNodeCondition*)Allocate(0x1c); if(p){ p->Init(); *(void**)p=&CFightNodeConditionVtable; return p; } return 0; }