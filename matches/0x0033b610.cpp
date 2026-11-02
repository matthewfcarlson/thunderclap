extern "C" double __cdecl calc(int, int);
extern "C" double __cdecl fabs(double);
extern "C" void __cdecl apply(int, float);
extern "C" int __cdecl FUN_0033b610(int x) {
    apply(x, (float)fabs(calc(x, 1)));
    return 1;
}