extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" char __cdecl FUN_00345b90(int);
extern "C" char __cdecl FUN_002771b0(char*);
extern "C" void __cdecl FUN_0026d850(void*);
extern "C" void __cdecl FUN_0026d840(void*);
extern "C" char gLock[1];
extern "C" char gText[16];
extern "C" char gLast;
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
        FUN_0026d850(gLock);
        strncpy(gText, local, 16);
        gLast = 0;
        FUN_0026d840(gLock);
        return 1;
    }
    return 0;
}