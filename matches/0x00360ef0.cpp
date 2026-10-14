extern "C" int __cdecl atexit(void (*)(void));
class G_360ef0 {
  public:
    void Reg();
};
G_360ef0 g_360ef0;
void Cleanup();
void Init() {
    g_360ef0.Reg();
    atexit(Cleanup);
}
