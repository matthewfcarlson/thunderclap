struct Pair {
    int a, b;
};
extern "C" Pair __cdecl FUN_0027b020(int);
extern int g1;
extern int g2;
void __cdecl FUN_0035e100() {
    Pair r = FUN_0027b020(0x40048c);
    g1 = r.a;
    g2 = r.b;
}
