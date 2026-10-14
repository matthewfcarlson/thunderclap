extern "C" void __cdecl FUN_003640c0();
extern "C" int __cdecl _atexit(void (*func)(void));
struct Sound {
    void Init(const char* path, int flag);
};
extern Sound gSound;
void __cdecl FUN_0035edd0() {
    gSound.Init("sound/rsd", 0);
    _atexit(FUN_003640c0);
}
