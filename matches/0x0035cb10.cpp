extern "C" int __cdecl _atexit(void (*)());
struct Global {
    void Init();
};
extern Global gGlobal_35cb10;
void Cleanup();
void FUN_0035cb10() {
    gGlobal_35cb10.Init();
    _atexit(Cleanup);
}
