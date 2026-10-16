struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
extern Pair gPair;
void FUN_0035da50() {
    gPair = FUN_0027b020("$MACRO_DEFINE");
}