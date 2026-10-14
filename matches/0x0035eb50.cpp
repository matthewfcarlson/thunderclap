extern "C" unsigned __int64 __cdecl FUN_0027b020(const char* name);
struct Pair {
    unsigned int lo, hi;
};
extern Pair gPair;
void __cdecl FUN_0035eb50() {
    __int64 v = FUN_0027b020("mercyFuelRod2");
    gPair = *(Pair*)&v;
}
