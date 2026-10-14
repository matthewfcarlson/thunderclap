class Mgr_35fac0 {
  public:
    void Init();
};
extern Mgr_35fac0 g_mgr_35fac0;
extern void Cleanup();
extern int __cdecl atexit(void (*)(void));
void FUN_0035fac0() {
    g_mgr_35fac0.Init();
    atexit(Cleanup);
}
