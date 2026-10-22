class SeqEventStopTrackType_360310 {
  public:
    void Run();
};

extern SeqEventStopTrackType_360310 g_mgr_360310;

void Cleanup() throw() {}

int atexit(void (*)(void));

void FUN_00360310() {
    g_mgr_360310.Run();
    atexit(Cleanup);
}
