extern "C" long __cdecl atol(const char*);
struct Parser {
    const char* Get();
};
char __stdcall FUN_00336030(int** p, Parser* parser, int unused, char direct) {
    const char* s = parser->Get();
    if (!s)
        return 0;
    if (direct) {
        *(int*)p = atol(s);
        return 1;
    }
    int* q = *p;
    *q = atol(s);
    return 1;
}