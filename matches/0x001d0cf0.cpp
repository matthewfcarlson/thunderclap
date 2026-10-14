typedef int(__cdecl* Fn_1d0cf0)(int);
extern int __cdecl FUN_00212d70(int);
extern Fn_1d0cf0 __cdecl FUN_00213260(int, int);
extern int __cdecl FUN_00212de0(int, int);
int __cdecl FUN_001d0cf0(int param) {
    int i = FUN_00212d70(param);
    if (i < 1)
        return 0;
    Fn_1d0cf0 pc = FUN_00213260(param, -1);
    FUN_00212de0(param, -1);
    return pc(param);
}