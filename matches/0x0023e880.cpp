typedef unsigned int U;
extern void* __cdecl FUN_0008d690(int);
class Helper { public: U FUN_0023e610(U,U,U,U); };
class StopTrack { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual U vfunc_10(U a,U b,U c); };
U StopTrack::vfunc_10(U a,U b,U c) { Helper* p=(Helper*)FUN_0008d690(0x2c); if(p) return p->FUN_0023e610(a,(U)this,b,c); return 0; }