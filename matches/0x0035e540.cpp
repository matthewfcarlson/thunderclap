extern "C" void _atexit(void (*)());
extern char g_s2[];
class C {
  public:
    void Reg(const char*, void*);
};
void __cdecl Cleanup() throw();
void __cdecl Hook() {
    ((C*)0x4e1768)->Reg(g_s2, 0);
    _atexit(Cleanup);
}
