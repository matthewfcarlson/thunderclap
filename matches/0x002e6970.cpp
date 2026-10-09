typedef unsigned int U32;
struct S { char pad[0x40]; U32 a; U32 b; U32 c; };
void FUN_002e6970(S* p, U32 x, U32 y, U32 z) { p->c=x; p->a=y; p->b=z; }