struct Pair_35c7e0 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Pair_35c7e0 __cdecl FUN_0027b020(const char*);
extern unsigned int gObjLo;
extern unsigned int gObjHi;

void FUN_0035c7e0() {
    Pair_35c7e0 p = FUN_0027b020("blackhawk_leader");
    gObjLo = p.lo;
    gObjHi = p.hi;
}
