extern "C" int __cdecl _atexit(void (*)(void));
struct Mgr {
    void Init(const char*, int);
};
extern Mgr g_mgr;
extern const char k_path[];
extern void __cdecl shutdown(void);
void __cdecl FUN_0035e690() {
    g_mgr.Init(k_path, 0);
    _atexit(shutdown);
}
