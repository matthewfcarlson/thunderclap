struct ThisWrap_000e74e0 {
    int Inner(int);
    int Target(int x);
};
extern int __cdecl FUN_00344e74(int, int, void*, void*, int);
extern char DAT_0049dba4, DAT_0049f4f0, DAT_0049f470;
int ThisWrap_000e74e0::Target(int x) {
    return FUN_00344e74(FUN_00344e74(this->Inner(x), 0, &DAT_0049dba4, &DAT_0049f4f0, 0), 0, &DAT_0049f4f0, &DAT_0049f470, 0);
}