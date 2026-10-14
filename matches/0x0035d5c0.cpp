struct Pair {
    int a;
    int b;
};
Pair __cdecl FUN_0027b020(int*);
extern int gFirst;
extern int gSecond;
void FUN_0035d5c0() {
    Pair p = FUN_0027b020((int*)0x40048c);
    gFirst = p.a;
    gSecond = p.b;
}