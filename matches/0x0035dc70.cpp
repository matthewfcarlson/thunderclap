extern "C" unsigned long long __cdecl FUN_0027b020(const char*);
extern int g_a;
extern int g_b;
void __cdecl FUN_0035dc70() {
    unsigned long long r = FUN_0027b020("$MACRO_DEFINE");
    g_a = (int)r;
    g_b = (int)(r >> 32);
}
