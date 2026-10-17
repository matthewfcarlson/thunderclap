// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CChaseAgent::vfunc_7 @ 0x000fcad0
struct ChaseState { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void set(int); };
struct ChaseSource { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual int lookup(const char*, unsigned int); ChaseState* FUN_000fefc0(); };
struct CChaseAgent { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(int); virtual void vfunc_8(int); char pad[0x58-4]; ChaseSource* source; };
void CChaseAgent::vfunc_7(int enabled) { if ((char)enabled) vfunc_8(source->lookup("Chase", 0xffff0000)); source->FUN_000fefc0()->set(enabled); }