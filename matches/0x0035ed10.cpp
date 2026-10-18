extern "C" void __cdecl FUN_00364070();
extern "C" void _atexit(void (*)());
void __cdecl FUN_0023fc40(const char*, int);
struct G {
    void Init(const char*, int);
};
extern G g;
void __cdecl FUN_0035ed10() {
    g.Init("sound/rsd", 0);
    _atexit(FUN_00364070);
}
