extern "C" int __cdecl atexit(void (*)());
struct Mgr_3604d0 {
    void Init();
};
extern Mgr_3604d0 g_mgr_3604d0;
void Register() {
    g_mgr_3604d0.Init();
    atexit((void (*)())0x364490);
}
