struct Pair {
    unsigned a, b;
};
extern unsigned gInput;
extern Pair gOutput;
extern "C" Pair __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
void FUN_0035f210() {
    gOutput = FUN_002672f0(gInput, 0, 0);
}