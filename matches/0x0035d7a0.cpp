extern "C" int atexit(void (*)());
struct Module {
    void* Register(const char* name, int n);
};
void Cleanup() {}
void FUN_0035d7a0() {
    Module* m = (Module*)0x4ddf9c;
    m->Register("sound/rsd", 0);
    atexit(Cleanup);
}
