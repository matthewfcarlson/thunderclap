class Sub {
  public:
    void Init(const char* path, int flag);
};
extern Sub g_sub;
void __cdecl Reg(void* f);
void __cdecl Cleanup();
void __cdecl InitSub() {
    g_sub.Init("sound/rsd", 0);
    Reg(Cleanup);
}
