class Mgr_360310 {
  public:
    void Run();
};

extern Mgr_360310 g_mgr_360310;

void Cleanup() throw() {}

int atexit(void (*)(void));

void FUN_00360310() {
    g_mgr_360310.Run();
    atexit(Cleanup);
}
