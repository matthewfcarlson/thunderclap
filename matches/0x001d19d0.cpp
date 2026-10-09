typedef unsigned int u32;
extern void __cdecl Callee(u32, u32);
class Obj { char pad[8]; u32 value; public: unsigned char Target(u32 arg); };
unsigned char Obj::Target(u32 arg) { Callee(value, 0xffffffffu - arg); return 1; }