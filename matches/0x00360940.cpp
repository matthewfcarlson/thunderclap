extern "C" int __cdecl _atexit(void (*)(void));
struct Cleanup {
    void Run();
};
extern Cleanup g_cleanup;
void FUN_00360940() {
    g_cleanup.Run();
    _atexit((void (*)(void))0x364530);
}
