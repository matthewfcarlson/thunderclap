class G {
  public:
    void Init(const char* path, int flag);
};
G g_obj;
void __cdecl Reg() {
    g_obj.Init("sound/rsd", 0);
    atexit((void (*)())0x363c80);
}
