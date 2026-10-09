typedef unsigned int u32;
struct Data { u32 a; u32 b; };
struct Obj { char pad[8]; u32 flags; char pad2[0x30]; u32 x; u32 y; };
void FUN_002eb6f0(int p1, Obj* p2, Data* p3) {
    if (p1 && p2) {
        p2->x = p3->a;
        p2->y = p3->b;
        p2->flags |= 0x200;
    }
}