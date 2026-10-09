struct Obj { void call(int); void tail(); };
struct Inner { char pad[8]; Obj* p; };
struct Global { char pad[0x20]; Inner* inner; };
extern Global* g;
extern Obj* __cdecl FUN_000678d0();
class ThreatBallAction { public: char pad[0x24]; int field; void vfunc_4(); };
void ThreatBallAction::vfunc_4() { g->inner->p->call(field); field = 0; FUN_000678d0()->tail(); }