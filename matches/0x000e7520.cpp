struct ThisWrap_000e7520 {
    int FUN_000e7260(int);
    int FUN_000e7520(int x);
};
extern int __cdecl FUN_00344e74(int, int, int, int, int);
extern int a, b, c;
int ThisWrap_000e7520::FUN_000e7520(int x) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(x), 0, (int)&a, (int)&b, 0), 0, (int)&b, (int)&c, 0);
}