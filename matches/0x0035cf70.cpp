extern "C" void _atexit(void (*)(void));
class Thing {
  public:
    void Init(const char* name, int flag);
};
extern Thing g_thing;
void __cdecl FUN_00363c70(void);
void __cdecl FUN_0035cf70(void) {
    g_thing.Init("sound/rsd", 0);
    _atexit(FUN_00363c70);
}
