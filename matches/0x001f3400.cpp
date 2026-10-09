typedef unsigned int u32;
void F249A90(u32 a, u32* b);
void F24A800(u32 a, int b);
void F2497E0(u32 a);
struct Pair {
    u32 x;
    u32 y;
};
struct Obj {
    char pad0[4];
    u32 a;
    char pad8[16];
    u32 b;
    void Target(u32);
};
void Obj::Target(u32 param) {
    Pair p;
    if (a != 0) {
        p.x = 0;
        p.y = param;
        F249A90(a, &p.x);
        F24A800(a, 0x32);
        if (b != 0) {
            F2497E0(b);
            b = 0;
        }
    }
}
