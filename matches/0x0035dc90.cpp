struct Pair {
    unsigned a, b;
};
extern Pair __cdecl getPair(const char*);
extern Pair globalPair;
void target() {
    globalPair = getPair("$MACRO_INSERT");
}