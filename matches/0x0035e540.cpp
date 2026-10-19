extern "C" char hulk_at_004e1768[];
extern "C" void _atexit(void (*)());
extern char g_s2[];
class C {
  public:
    void Reg(const char*, void*);
};
void __cdecl Cleanup() throw();
void __cdecl Hook() {
    ((C*)((int)hulk_at_004e1768))->Reg(g_s2, 0);
    _atexit(Cleanup);
}
