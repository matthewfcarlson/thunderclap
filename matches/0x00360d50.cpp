extern "C" void __cdecl _atexit(void (*)());
struct G {
    void Init();
};
extern G g;
extern void Cleanup();
void __cdecl FUN_00360d50() {
    g.Init();
    _atexit(Cleanup);
}
