struct Pair {
    int a;
    int b;
};
extern Pair __cdecl Lookup(const char*);
extern Pair globalPair;
void FUN_0035c920() {
    globalPair = Lookup("destroyer");
}