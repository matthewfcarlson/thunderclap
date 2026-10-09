class CAction { public: virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual bool vfunc_7(int); virtual void a8(); };
class CClimbingAction : public CAction { public: char pad[0x1c - 4]; void* mThing; bool vfunc_7(int); };
struct X { X* f1(); X* f2(); int f3(int); };
bool CClimbingAction::vfunc_7(int) { X* x = (X*)mThing; x = x->f1(); x = x->f2(); x->f3(4); return true; }