typedef unsigned int U;
U __stdcall FUN_000f7d30(U);
struct A { void f(U); void target(U); };
void A::target(U x) { U r = FUN_000f7d30(x); f(r); }