struct Obj { Obj* first(); Obj* second(); void third(int); void fourth(int); };
struct CAction { virtual void q(); char pad[0x18]; Obj* mObj; };
struct CInvulnerableAction : CAction { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual bool vfunc_6(int); virtual void v7(); virtual void v8(); };
bool CInvulnerableAction::vfunc_6(int x) { Obj* a=mObj->first(); Obj* b=a->second(); b->third(1); b->fourth(1); return true; }