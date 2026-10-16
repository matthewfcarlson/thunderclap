class Sound {
  public:
    void Init(const char*, int);
};
extern Sound gSound;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Shutdown();
void __cdecl FUN_0035d4a0() {
    gSound.Init("sound/rsd", 0);
    atexit(Shutdown);
}