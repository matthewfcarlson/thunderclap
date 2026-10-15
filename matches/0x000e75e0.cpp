extern int __stdcall FUN_000e7260(int);
extern int FUN_00344e74(int, int, int*, int*, int);
extern int a, b, c;
int __stdcall FUN_000e75e0(int x) {
    return FUN_00344e74(FUN_00344e74(FUN_000e7260(x), 0, &a, &b, 0), 0, &b, &c, 0);
}