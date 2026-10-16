class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
extern Sound sound;
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
void init() {
    sound.Sound::Sound("sound/rsd", 0);
    atexit(cleanup);
}