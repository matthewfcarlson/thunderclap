extern "C" char DAT_003fd600[];
extern "C" char DAT_00434af8[];
extern void __cdecl FUN_003390d0(int, const char*, const char*, int);
int target(int a) {
    FUN_003390d0(a, (const char*)((int)DAT_003fd600), (const char*)((int)DAT_00434af8), 0);
    return 1;
}