typedef unsigned int u32;
struct Thing { char pad[0x68]; u32 flags; };
void __cdecl FUN_002d8820(Thing* p) { p->flags |= 0x400; }