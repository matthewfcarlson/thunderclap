typedef unsigned int u32_2eb6f0;
struct Data_2eb6f0 {
    u32_2eb6f0 a;
    u32_2eb6f0 b;
};
struct Obj_2eb6f0 {
    char pad[8];
    u32_2eb6f0 flags;
    char pad2[0x30];
    u32_2eb6f0 x;
    u32_2eb6f0 y;
};
void FUN_002eb6f0(int p1, Obj_2eb6f0* p2, Data_2eb6f0* p3) {
    if (p1 && p2) {
        p2->x = p3->a;
        p2->y = p3->b;
        p2->flags |= 0x200;
    }
}