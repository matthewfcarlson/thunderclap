typedef struct {
    unsigned lo;
    unsigned hi;
} Pair_35e120;
extern Pair_35e120 __cdecl FUN_0027b020(const char*);
extern unsigned g1_35e120;
extern unsigned g2_35e120;
void __cdecl FUN_0035e120() {
    Pair_35e120 r = FUN_0027b020("$MACRO_DEFINE");
    g1_35e120 = r.lo;
    g2_35e120 = r.hi;
}
