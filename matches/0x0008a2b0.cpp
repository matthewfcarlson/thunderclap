struct A_8a2b0 {
    char p0[0x80];
    int x;
    char p1[0x84];
    int y;
    char p2[0x9ac];
    int z;
};
extern "C" int __fastcall FUN_0008a2b0(A_8a2b0* a) {
    int v = a->z;
    if (v == 1 && a->x < 10 && a->y > 4)
        v = 0;
    return v;
}