struct Pair {
    int a, b;
};
extern Pair __cdecl lookup(const char*);
extern Pair result;
void FUN_0035d9d0() {
    result = lookup("GameInstaceLocators");
}