extern void* g_global;
extern void __fastcall target_func(void*);
extern "C" void __cdecl FUN_00364370() {
    target_func(&g_global);
}