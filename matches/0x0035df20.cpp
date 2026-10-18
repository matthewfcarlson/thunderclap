struct Pair_35df20 {
    int lo;
    int hi;
};
extern "C" Pair_35df20 __cdecl DEFINE(const char* name);
extern char g_hi_35df20[4];
extern char g_lo_35df20[4];
void __cdecl FUN_0035df20() {
    Pair_35df20 r = DEFINE("$MACRO_DEFINE");
    *(int*)g_lo_35df20 = r.lo;
    *(int*)g_hi_35df20 = r.hi;
}
