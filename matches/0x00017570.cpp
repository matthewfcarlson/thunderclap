// Same code shape as 0x00016580 (propagated; names are from that function)
struct ObjA { ObjA* f(); };
struct ObjB { ObjB* g(); };
struct ObjC { void h(int); };
class CInvincibleAction { char pad[0x1c]; ObjA* member; public: bool vfunc_6(int); };
bool CInvincibleAction::vfunc_6(int) { ObjA* a = member->f(); ObjB* b = ((ObjB*)a)->g(); ((ObjC*)b)->h(1); return true; }