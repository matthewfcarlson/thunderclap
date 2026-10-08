// Same code shape as 0x00363af0 (propagated; names are from that function)
struct Obj { void f(); };
extern Obj g;
void wrapper() { g.f(); }