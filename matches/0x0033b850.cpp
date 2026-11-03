extern double __cdecl FUN_00339ec0(int, int);
extern void __cdecl FUN_00213340(int, float);
extern "C" double sqrt(double);
extern "C" int __cdecl FUN_0033b850(int L) {
    double x = FUN_00339ec0(L, 1);
    FUN_00213340(L, (float)sqrt(x));
    return 1;
}
