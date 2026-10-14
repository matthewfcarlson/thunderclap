struct Pair {
    int a;
    int b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
extern Pair g_hash;
void __cdecl FUN_0035ca50() {
    g_hash = FUN_0027b020("jumping");
}
