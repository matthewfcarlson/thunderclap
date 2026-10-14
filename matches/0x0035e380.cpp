extern char g_sound_rsd[];
extern char* g_bss;
extern void __cdecl _atexit(void (*)());
class Sound {
  public:
    void Init(const char* b, int a);
};
extern Sound g_sound;
void FUN_0035e380() {
    g_sound.Init(g_sound_rsd, 0);
    _atexit((void (*)())0x363f40);
}
