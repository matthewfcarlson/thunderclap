extern "C" int __cdecl _atexit(void (*)());
struct Sound {
    void Reg(const char*, int);
};
Sound gSound;
void Handler() {}
void Init() {
    gSound.Reg("sound/rsd", 0);
    _atexit(Handler);
}
