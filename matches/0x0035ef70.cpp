class Sound {
  public:
    void Init(const char*, int);
};
extern Sound gSound;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void __cdecl target() {
    gSound.Init("sound/rsd", 0);
    atexit(cleanup);
}