struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
extern int g_a;
extern int g_b;
void __cdecl FUN_0035d620() {
    Pair p = FUN_0027b020("AddBackground");
    g_a = p.a;
    g_b = p.b;
}
