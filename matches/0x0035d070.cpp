class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern Sound gSound;
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl cleanup();
void initSound() {
    gSound.Sound::Sound("sound/rsd", 0);
    atexit(cleanup);
}
