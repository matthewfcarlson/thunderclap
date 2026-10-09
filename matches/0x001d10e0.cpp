extern "C" void __cdecl FUN_002135a0(int, int, int);
extern "C" int __cdecl FUN_00212f00(int, int);
extern "C" void __cdecl FUN_00212d80(int, int);
extern "C" int __cdecl FUN_00213190(int, int);
int __stdcall FUN_001d10e0(int param_1, int param_2) {
    FUN_002135a0(param_2, 0xffffd8ef, param_1);
    int i = FUN_00212f00(param_2, -1);
    if (i != 4) {
        FUN_00212d80(param_2, -2);
        return 0;
    }
    int result = FUN_00213190(param_2, -1);
    FUN_00212d80(param_2, -2);
    return result;
}