extern "C" int __cdecl atexit(void (*)(void));
class Reg {
  public:
    void Register(const char* name, int a);
};
void F2() {}
extern Reg g_reg;
void RegF() {
    g_reg.Register("sound/rsd", 0);
    atexit(F2);
}
