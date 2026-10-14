struct R64 {
    int lo;
    int hi;
};
extern int g004ca260;
extern int g004e5ba8;
extern int g004e5bac;
extern R64 __cdecl FUN_002672f0(int, int, int);
void __cdecl FUN_0035f070() {
    R64 r = FUN_002672f0(g004ca260, 0, 0);
    g004e5ba8 = r.lo;
    g004e5bac = r.hi;
}
