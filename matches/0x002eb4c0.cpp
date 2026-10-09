typedef unsigned short u16;
typedef unsigned int u32;
struct Obj { char pad0[8]; u32 flags; char padc[4]; u32 field10; u16 field14; };
void FUN_002eb4c0(int a, Obj* b, u32 c, u16 d) {
    if (a && b) {
        b->field10 = c;
        b->field14 = d;
        b->flags |= 8;
    }
}