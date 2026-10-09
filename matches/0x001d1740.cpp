extern "C" void __cdecl F2133d0(const char*, const char*);
extern "C" void __cdecl F213680(const char*, int, int);
extern "C" void __cdecl F213800(const char*, int);
extern "C" void __cdecl F212ed0(const char*, int);
extern "C" void __cdecl F213790(const char*, int, const char*);
extern "C" void __cdecl F213380(const char*, const char*, int);
extern "C" char* g_tB;
void __stdcall FUN_001d1740(const char* s) {
    F2133d0(s, g_tB);
    F213680(s, 0, 0);
    F213800(s, -10000);
    F212ed0(s, -10000);
    F213790(s, -10001, "HC_REGISTRY");
    F213380(s, "context", 7);
    F213680(s, 0, 0);
    F213380(s, "event", 5);
    F213680(s, 0, 0);
    F213800(s, -3);
    F213800(s, -10001);
}