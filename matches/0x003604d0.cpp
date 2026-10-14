extern "C" int __cdecl atexit(void (*)());
struct Mgr {
    void Init();
};
extern Mgr g_mgr;
void Register() {
    g_mgr.Init();
    atexit((void (*)())0x364490);
}
