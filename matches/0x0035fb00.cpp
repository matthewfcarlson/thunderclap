extern "C" int atexit(void (*)());
struct ListenerEffectPs2Type_35fb00 {
    void Init();
};
extern ListenerEffectPs2Type_35fb00 gCfg;
extern void Cleanup();
void FUN_0035fb00() {
    gCfg.Init();
    atexit(Cleanup);
}
