class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern Sound gSound;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_0035e700() {
    gSound.Sound::Sound("sound/rsd", 0);
    atexit(cleanup);
}