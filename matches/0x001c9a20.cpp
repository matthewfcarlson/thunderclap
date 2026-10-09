typedef unsigned int u32;
struct Obj { u32 pad; u32 target(u32); };
void __stdcall FUN_001c9750(int, int, u32);
u32 Obj::target(u32 param) { FUN_001c9750(2, 0xb0, param); return (u32)this; }