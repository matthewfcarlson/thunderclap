class Sound {
  public:
    Sound(const char*, int);
};
extern Sound gSound;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void init() {
    gSound.Sound::Sound("sound/rsd", 0);
    atexit(cleanup);
}