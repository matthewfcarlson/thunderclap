extern int g;
struct A { char pad[12]; int value; };
void __stdcall FUN_001b68d0(A* p) { g = p->value; }