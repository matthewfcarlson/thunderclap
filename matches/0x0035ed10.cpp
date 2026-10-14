extern "C" void _atexit(void (*)());
void __cdecl FUN_0023fc40(const char*, int);
struct G {
    void Init(const char*, int);
};
extern G g;
void __cdecl FUN_0035ed10() {
    g.Init("sound/rsd", 0);
    _atexit((void (*)())0x364070);
}
