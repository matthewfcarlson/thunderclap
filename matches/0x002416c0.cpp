typedef unsigned int u32;
struct Obj { char pad0[0x28]; u32 value; char pad2[8]; int state; };
void __cdecl FUN_002416c0(u32 a, Obj* obj, u32 value) { if (obj->state != 0) { obj->state = 3; obj->value = value; } }