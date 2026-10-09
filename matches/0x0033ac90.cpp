extern "C" void __cdecl FUN_003390d0(void*, const char*, void*, int);
extern "C" void __cdecl FUN_002134a0(void*, void*, int);
extern "C" void __cdecl FUN_00213790(void*, int, const char*);
extern "C" void FUN_0033aa40();
extern "C" char g_4347a8;
extern "C" int __cdecl FUN_0033ac90(void* p) {
    FUN_003390d0(p, "debug", &g_4347a8, 0);
    FUN_002134a0(p, (void*)&FUN_0033aa40, 0);
    FUN_00213790(p, 0xffffd8ef, "_TRACEBACK");
    return 1;
}