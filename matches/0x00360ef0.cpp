extern "C" int __cdecl atexit(void (*)(void));
class SeqEventClipType_360ef0 {
  public:
    void Reg();
};
SeqEventClipType_360ef0 g_360ef0;
extern "C" void FUN_00364610();
void Init() {
    g_360ef0.Reg();
    atexit(FUN_00364610);
}
