extern "C" int atexit(void (*)());
struct Cfg_35fb00 {
    void Init();
};
extern Cfg_35fb00 gCfg;
extern void Cleanup();
void FUN_0035fb00() {
    gCfg.Init();
    atexit(Cleanup);
}
