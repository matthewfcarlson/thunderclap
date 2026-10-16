struct Pair {
    unsigned a;
    unsigned b;
};
extern Pair __cdecl FUN_0027b020(const char*);
extern Pair gPair;
void FUN_0035da70() {
    gPair = FUN_0027b020("$MACRO_INSERT");
}