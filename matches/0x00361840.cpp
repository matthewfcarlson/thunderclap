extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
void RegisterCleanup() {
    atexit(Cleanup);
}
