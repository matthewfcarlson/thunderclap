struct Obj {
    char pad0[0x28];
    int field28;
    char pad2c[8];
    int field34;
};
void FUN_00242da0(int a, Obj* b);
void FUN_00242f60(int a, Obj* b, int c) {
    if (b->field34 == 0)
        FUN_00242da0(a, b);
    if (b->field34 != 2) {
        b->field34 = 1;
        b->field28 = c;
    }
}