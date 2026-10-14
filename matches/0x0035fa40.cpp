typedef void (*AtExitFn)();
void __cdecl _atexit(AtExitFn);
struct Registry {
    void Reg(const char* name, int flags);
};
extern Registry gRegistry;
extern void __cdecl Cleanup();
void __cdecl RegisterEffect() {
    gRegistry.Reg("ListenerEffectWin32", 0);
    _atexit((AtExitFn)Cleanup);
}
