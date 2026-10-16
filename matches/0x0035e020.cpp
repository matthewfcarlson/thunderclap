struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
extern Pair gResult;
void FUN_0035e020() {
    gResult = FUN_0027b020("$MACRO_DEFINE");
}