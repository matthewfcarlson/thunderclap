extern "C" int __cdecl atexit(void (*)(void));
class SeqEventClipType_360ef0 {
  public:
    void Reg();
};
SeqEventClipType_360ef0 g_360ef0;
void Cleanup();
void Init() {
    g_360ef0.Reg();
    atexit(Cleanup);
}
