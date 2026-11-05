extern "C" int __cdecl atexit(void (*)(void));
class SeqEventClipType_360ef0 {
  public:
    void FUN_00255f70();
};
SeqEventClipType_360ef0 g_360ef0;
extern "C" void FUN_00364610();
void Init() {
    g_360ef0.FUN_00255f70();
    atexit(FUN_00364610);
}
