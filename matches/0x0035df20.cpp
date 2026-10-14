extern "C" struct Pair {
    int lo;
    int hi;
} __cdecl DEFINE(const char* name);
extern char g_hi[4];
extern char g_lo[4];
void __cdecl FUN_0035df20() {
    Pair r = DEFINE("$MACRO_DEFINE");
    *(int*)g_lo = r.lo;
    *(int*)g_hi = r.hi;
}
