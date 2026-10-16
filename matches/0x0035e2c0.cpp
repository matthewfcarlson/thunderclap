struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
extern Pair result;
void __cdecl FUN_0035e2c0() {
    result = FUN_0027b020("locator");
}