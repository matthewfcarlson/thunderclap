extern int DAT_0049f4a4, DAT_0049f4f0, DAT_0049dba4;
struct ThisWrap_000e74a0 {
    int inner(int);
    int target(int x);
};
int __cdecl FUN_00344e74(int, int, int*, int*, int);
int ThisWrap_000e74a0::target(int x) {
    return FUN_00344e74(FUN_00344e74(this->inner(x), 0, &DAT_0049dba4, &DAT_0049f4f0, 0), 0, &DAT_0049f4f0, &DAT_0049f4a4, 0);
}