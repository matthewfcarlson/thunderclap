extern "C" char hulk_at_0040048c[];
struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(int);
extern Pair g;
void FUN_0035d500() {
    g = FUN_0027b020(((int)hulk_at_0040048c));
}