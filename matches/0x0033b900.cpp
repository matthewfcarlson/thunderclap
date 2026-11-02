extern "C" double __cdecl calc(int, int);
extern "C" double __cdecl log10(double);
extern "C" void __cdecl output(int, float);
extern "C" int __cdecl FUN_0033b900(int x) {
    output(x, (float)log10(calc(x, 1)));
    return 1;
}