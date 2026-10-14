extern "C" void __cdecl _atexit(void (*)());
struct G_360d50 {
    void Init();
};
extern G_360d50 g_360d50;
extern void Cleanup();
void __cdecl FUN_00360d50() {
    g_360d50.Init();
    _atexit(Cleanup);
}
