extern "C" struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
extern "C" Pair g_pair;
void FUN_0035df40() {
    g_pair = FUN_0027b020("$MACRO_INSERT");
}