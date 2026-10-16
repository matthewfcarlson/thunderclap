struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
extern "C" Pair gValue;
extern "C" void __cdecl FUN_0035e1c0() {
    gValue = FUN_0027b020("$MACRO_INSERT");
}