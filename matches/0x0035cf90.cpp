extern "C" void __cdecl FUN_00363c80();
class G {
  public:
    void Init(const char* path, int flag);
};
G g_obj;
void __cdecl Reg() {
    g_obj.Init("sound/rsd", 0);
    atexit(FUN_00363c80);
}
