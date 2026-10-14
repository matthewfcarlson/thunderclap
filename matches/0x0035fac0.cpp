class Mgr {
  public:
    void Init();
};
extern Mgr g_mgr;
extern void Cleanup();
extern int __cdecl atexit(void (*)(void));
void FUN_0035fac0() {
    g_mgr.Init();
    atexit(Cleanup);
}
