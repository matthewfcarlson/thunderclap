typedef unsigned int u32_1dca50;
struct Pair_1dca50 {
    u32_1dca50 a, b;
};
Pair_1dca50 FUN_0027b020(u32_1dca50);
void FUN_002f2750(u32_1dca50, u32_1dca50);
void FUN_002f28d0(u32_1dca50, u32_1dca50, u32_1dca50, u32_1dca50, u32_1dca50);
void FUN_001dca50(u32_1dca50 p1, u32_1dca50 p2, u32_1dca50 p3, u32_1dca50 p4, u32_1dca50 p5) {
    Pair_1dca50 q = FUN_0027b020(p1);
    FUN_002f2750(q.a, q.b);
    FUN_002f28d0(p1, p2, p3, p4, p5);
}