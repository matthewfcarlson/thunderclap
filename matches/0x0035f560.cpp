struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
extern Pair gPair;
void FUN_0035f560() {
    gPair = FUN_002672f0("Unknown", 0, 0);
}