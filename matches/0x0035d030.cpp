extern "C" typedef struct {
    char* a;
    char* b;
} Pair_35d030;
extern "C" Pair_35d030 __cdecl MACRO_LOOKUP(const char*);
extern char g_name[];
extern char g_def[];

void FUN_0035d030() {
    Pair_35d030 p = MACRO_LOOKUP("$MACRO_DEFINE");
    *(const char**)&g_name = p.a;
    *(const char**)&g_def = p.b;
}
