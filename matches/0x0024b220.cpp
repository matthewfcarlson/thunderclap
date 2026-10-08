typedef unsigned char u8;
struct Obj { char pad[0xb9]; u8 value; };
int __cdecl FUN_0024b220(Obj* p) { return p->value; }