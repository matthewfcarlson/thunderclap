struct Pair_35e100 {
    int a, b;
};
extern "C" Pair_35e100 __cdecl FUN_0027b020(int);
extern int g1_35e100;
extern int g2_35e100;
void __cdecl FUN_0035e100() {
    Pair_35e100 r = FUN_0027b020(0x40048c);
    g1_35e100 = r.a;
    g2_35e100 = r.b;
}
