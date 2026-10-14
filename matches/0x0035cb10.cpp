extern "C" int __cdecl _atexit(void (*)());
struct Global {
    void Init();
};
extern Global gGlobal;
void Cleanup();
void FUN_0035cb10() {
    gGlobal.Init();
    _atexit(Cleanup);
}
