typedef struct {
    unsigned lo;
    unsigned hi;
} Pair;
extern Pair __cdecl FUN_0027b020(const char*);
extern unsigned g1;
extern unsigned g2;
void __cdecl FUN_0035e120() {
    Pair r = FUN_0027b020("$MACRO_DEFINE");
    g1 = r.lo;
    g2 = r.hi;
}
