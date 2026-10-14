class Mgr {
  public:
    void Run();
};

extern Mgr g_mgr;

void Cleanup() throw() {}

int atexit(void (*)(void));

void FUN_00360310() {
    g_mgr.Run();
    atexit(Cleanup);
}
