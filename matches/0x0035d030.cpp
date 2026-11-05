extern "C" typedef struct {
    char* a;
    char* b;
} Pair_35d030;
unsigned __int64 FUN_0027b020(const char* s);
extern char g_name[];
extern char g_def[];

void FUN_0035d030() {
    unsigned __int64 p = FUN_0027b020("$MACRO_DEFINE");
    *(unsigned int*)&g_name = (unsigned int)p;
    *(unsigned int*)&g_def = (unsigned int)(p >> 32);
}
