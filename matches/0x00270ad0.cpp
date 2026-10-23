extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" char __cdecl FUN_00345b90(int);
extern "C" char __cdecl FUN_002771b0(char*);
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
extern "C" char DAT_0052a0f0[1];
extern "C" char DAT_0052a10c[16];
extern "C" char DAT_0052a11c;
extern "C" char __cdecl FUN_00270ad0(char* param) {
    char local[17];
    strncpy(local, param, 16);
    local[16] = 0;
    char* p = local;
    char c = *p;
    while (c) {
        *p = FUN_00345b90((int)*p);
        ++p;
        c = *p;
    }
    if (FUN_002771b0(local)) {
        FUN_0026d850(DAT_0052a0f0);
        strncpy(DAT_0052a10c, local, 16);
        DAT_0052a11c = 0;
        FUN_0026d840(DAT_0052a0f0);
        return 1;
    }
    return 0;
}