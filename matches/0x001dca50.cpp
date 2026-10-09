typedef unsigned int u32;
struct Pair { u32 a,b; };
Pair FUN_0027b020(u32);
void FUN_002f2750(u32,u32);
void FUN_002f28d0(u32,u32,u32,u32,u32);
void FUN_001dca50(u32 p1,u32 p2,u32 p3,u32 p4,u32 p5) {
    Pair q = FUN_0027b020(p1);
    FUN_002f2750(q.a,q.b);
    FUN_002f28d0(p1,p2,p3,p4,p5);
}