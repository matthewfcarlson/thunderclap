extern int DAT_0049dbbc, DAT_0049f4f0, DAT_0049dba4;
struct ThisWrap_000e75a0 {
    int inner(int);
    int FUN_000e75a0(int x);
};
extern "C" int __cdecl FUN_00344e74(int, int, int*, int*, int);
int ThisWrap_000e75a0::FUN_000e75a0(int x) {
    return FUN_00344e74(FUN_00344e74(this->inner(x), 0, &DAT_0049dba4, &DAT_0049f4f0, 0), 0, &DAT_0049f4f0, &DAT_0049dbbc, 0);
}