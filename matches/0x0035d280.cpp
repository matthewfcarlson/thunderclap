extern "C" int atexit(void (*)(void));
struct G {
    void Init(const char*, int);
};
extern G g;
void Init() {
    g.Init("sound/rsd", 0);
    atexit((void (*)(void))0x363d00);
}
