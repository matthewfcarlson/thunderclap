struct ThisWrap_000e75e0 {
    int FUN_000e7260(int);
    int FUN_000e75e0(int x);
};
extern int FUN_00344e74(int, int, int*, int*, int);
extern int a, b, c;
int ThisWrap_000e75e0::FUN_000e75e0(int x) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(x), 0, &a, &b, 0), 0, &b, &c, 0);
}