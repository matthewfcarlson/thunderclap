extern "C" char hulk_at_004ddf9c[];
extern "C" int atexit(void (*)());
struct Module {
    void* Register(const char* name, int n);
};
void Cleanup() {}
void FUN_0035d7a0() {
    Module* m = (Module*)((int)hulk_at_004ddf9c);
    m->Register("sound/rsd", 0);
    atexit(Cleanup);
}
