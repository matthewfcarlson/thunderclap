extern int __stdcall FUN_000e7260(int);
extern int __cdecl FUN_00344e74(int, int, int, int, int);
extern int a, b, c;
void __stdcall FUN_000e7520(int x) {
    FUN_00344e74(FUN_00344e74(FUN_000e7260(x), 0, (int)&a, (int)&b, 0), 0, (int)&b, (int)&c, 0);
}