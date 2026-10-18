extern "C" void __cdecl FUN_00363d00();
extern "C" int atexit(void (*)(void));
struct G {
    void Init(const char*, int);
};
extern G g;
void Init() {
    g.Init("sound/rsd", 0);
    atexit(FUN_00363d00);
}
