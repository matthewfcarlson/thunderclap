// FUN_000993f0 @ 0x000993f0
struct Range_993f0 {
    void FUN_000a90f0(int which, int v);
    void FUN_000a9130(int which, int v);
    void FUN_000a9110(int which, int v);
};
struct Panel_993f0 {
    char pad0[0xc4];
    Range_993f0* range;
    void FUN_000993f0(int a1, int a2, int a3, int a4, int a5, int a6);
};

void Panel_993f0::FUN_000993f0(int a1, int a2, int a3, int a4, int a5, int a6) {
    range->FUN_000a90f0(0, a1 - 1);
    range->FUN_000a9130(0, a2 - 1);
    range->FUN_000a9110(0, a3);
    range->FUN_000a90f0(1, a4 - 1);
    range->FUN_000a9130(1, a5 - 1);
    range->FUN_000a9110(1, a6);
}
