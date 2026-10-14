typedef unsigned short u16_2eb4c0;
typedef unsigned int u32_2eb4c0;
struct Obj_2eb4c0 {
    char pad0[8];
    u32_2eb4c0 flags;
    char padc[4];
    u32_2eb4c0 field10;
    u16_2eb4c0 field14;
};
void FUN_002eb4c0(int a, Obj_2eb4c0* b, u32_2eb4c0 c, u16_2eb4c0 d) {
    if (a && b) {
        b->field10 = c;
        b->field14 = d;
        b->flags |= 8;
    }
}