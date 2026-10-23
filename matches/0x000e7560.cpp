extern char DAT_0049dba4[], DAT_0049f4f0[], DAT_0049f454[];
struct ThisWrap_000e7560 {
    int helper(int);
    int target(int x);
};
extern "C" int __cdecl FUN_00344e74(int, int, char*, char*, int);
int ThisWrap_000e7560::target(int x) {
    return FUN_00344e74(FUN_00344e74(this->helper(x), 0, DAT_0049dba4, DAT_0049f4f0, 0), 0, DAT_0049f4f0, DAT_0049f454, 0);
}