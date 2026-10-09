struct H1 { void* f(); }; struct H2 { void* f(); }; struct H3 { char p[0x64]; void* q; }; struct H4 { char p[0x1c]; void* z; }; struct Helper { char p[0x1c]; void f(void*, void*); };
class COpportunityBallAction { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual bool vfunc_6(int); virtual void v7(); virtual void v8(); char pad[0x18]; void* mA; void* mB; int index; int output; };
struct V { int a,b,c; }; struct B { char p[0x20]; V v; };
bool COpportunityBallAction::vfunc_6(int arg) { void* a=((H1*)mA)->f(); a=((H2*)a)->f(); V local=((B*)mB)->v; void* x=((H3*)a)->q; void* base=((H4*)x)->z; ((Helper*)((char*)base+(index<<6)))->f(&local,&output); return true; }
