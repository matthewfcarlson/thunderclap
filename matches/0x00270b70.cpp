extern char DAT_0052a0f0[];
extern char DAT_0052a10c[];
extern "C" void __cdecl FUN_0026d850(char*);
extern "C" void __cdecl FUN_0026d840(char*);
extern "C" void __cdecl FUN_00270b70(int param_1) {
    FUN_0026d850(DAT_0052a0f0);
    char* p = DAT_0052a10c;
    int d = param_1 - (int)DAT_0052a10c;
    char c;
    do {
        c = *p;
        *(p + d) = c;
        ++p;
    } while (c != 0);
    FUN_0026d840(DAT_0052a0f0);
}
