struct Pair {
    unsigned a, b;
};
extern const int gVal;
extern Pair __cdecl FUN_0027b020(const int*);
extern Pair g;
void FUN_0035db90() {
    g = FUN_0027b020(&gVal);
}