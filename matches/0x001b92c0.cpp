// Same code shape as 0x001b8900 (propagated; names are from that function)
typedef unsigned int u32;
struct Obj { void second(); };
Obj* __stdcall FUN_001c3d90(u32);
void __stdcall target(u32 param_1) { Obj* p = FUN_001c3d90(param_1); p->second(); }