extern "C" int __cdecl atexit(void (*)(void));
class G {
  public:
    void Reg();
};
G g;
void Cleanup();
void Init() {
    g.Reg();
    atexit(Cleanup);
}
