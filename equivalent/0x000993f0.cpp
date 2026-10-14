// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000993f0 @ 0x000993f0
struct Range {
    void FUN_000a90f0(int which, int v);
    void FUN_000a9130(int which, int v);
    void FUN_000a9110(int which, int v);
};
struct Panel {
    char pad0[0xc4];
    Range* range;
    void FUN_000993f0(int a1, int a2, int a3, int a4, int a5, int a6);
};

void Panel::FUN_000993f0(int a1, int a2, int a3, int a4, int a5, int a6) {
    range->FUN_000a90f0(0, a1 - 1);
    range->FUN_000a9130(0, a2 - 1);
    range->FUN_000a9110(0, a3);
    range->FUN_000a90f0(1, a4 - 1);
    range->FUN_000a9130(1, a5 - 1);
    range->FUN_000a9110(1, a6);
}
