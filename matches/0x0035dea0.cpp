extern "C" long long MACRO(const char*);
extern unsigned char g[8];
void __cdecl FUN_0035dea0() {
    long long v = MACRO("$MACRO_DEFINE");
    *(unsigned long long*)g = (unsigned long long)v;
}
