typedef unsigned int U32;
struct Obj { char pad[0x5c]; U32 value; };
U32 __cdecl FUN_002d6dd0(Obj* p) { return p->value; }