// Same code shape as 0x000238b0 (propagated; names are from that function)
typedef unsigned int U;
typedef unsigned __int64 U64;
extern U64 __cdecl FUN_0027b020(U);
struct Obj { void Second(U64); void Target(U); };
void Obj::Target(U param) { U64 a = FUN_0027b020(param); Second(a); }