struct Pair {
    int a;
    int b;
};
extern Pair __cdecl lookup(const char*);
extern Pair result;
void FUN_0035d660() {
    result = lookup("AddTextInput");
}