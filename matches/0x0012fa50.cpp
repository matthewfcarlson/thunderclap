// Same code shape as 0x0012fa00 (propagated; names are from that function)
typedef unsigned int u32;
class Result { public: void run(); };
class Helper { public: Result* run(u32); };
extern Helper* gGlobal;
class ActionBase { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual bool vfunc_3(void*, void*); virtual void f4(); virtual void f5(); };
class StatBeginTrialAction : public ActionBase { public: char pad18[0x18]; u32 m1c; u32 m20; bool vfunc_3(void*, void*); };
bool StatBeginTrialAction::vfunc_3(void*, void*) { if (!m20) return false; u32 x=*(u32*)(m1c+0x10); Result* q=gGlobal->run(x); q->run(); return true; }