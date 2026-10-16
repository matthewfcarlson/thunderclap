class Sound {
  public:
    void Init(const char*, int);
};
extern Sound gSound;
extern "C" void __cdecl cleanup();
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_0035cfb0() {
    gSound.Init("sound/rsd", 0);
    atexit(cleanup);
}