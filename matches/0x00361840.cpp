extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364800();
void RegisterCleanup() {
    atexit(FUN_00364800);
}
