extern "C" int atexit(void (*)());
struct Cfg {
    void Init();
};
extern Cfg gCfg;
extern void Cleanup();
void FUN_0035fb00() {
    gCfg.Init();
    atexit(Cleanup);
}
