typedef unsigned int u32;
struct Inner { char pad[0x24]; u32 value; };
struct Outer { char pad[0x10]; Inner* inner; };
u32 __cdecl FUN_0024b0d0(Outer* p) { return p->inner->value; }
