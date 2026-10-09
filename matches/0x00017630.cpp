class CAction { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual bool vfunc_6(int); virtual void a7(); virtual void a8(); };
class Obj { public: void* first(); void* second(); void third(int); };
class CRageModeAction : public CAction { public: char pad[0x1c - 4]; Obj* member1; int member2; bool vfunc_6(int); };
bool CRageModeAction::vfunc_6(int arg) { Obj* x = (Obj*)member1->first(); x = (Obj*)x->second(); x->third(member2); return true; }