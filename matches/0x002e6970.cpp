typedef unsigned int U32_2e6970;
struct S_2e6970 {
    char pad[0x40];
    U32_2e6970 a;
    U32_2e6970 b;
    U32_2e6970 c;
};
void FUN_002e6970(S_2e6970* p, U32_2e6970 x, U32_2e6970 y, U32_2e6970 z) {
    p->c = x;
    p->a = y;
    p->b = z;
}