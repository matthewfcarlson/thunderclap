typedef unsigned short u16;
struct Obj { char pad[0x3c]; u16 value; };
void FUN_00247a10(Obj* p) { ++p->value; }