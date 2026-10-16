extern "C" int __cdecl atexit(void(__cdecl*)());
class Sound {
  public:
    Sound(const char*, int);
    ~Sound();
};
Sound gSound("sound/rsd", 0);