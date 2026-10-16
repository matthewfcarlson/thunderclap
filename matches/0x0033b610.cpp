extern "C" double __cdecl calc(int, int);
extern "C" double __cdecl fabs(double);
extern "C" void __cdecl apply(int, float);
int __cdecl target(int x) {
    apply(x, (float)fabs(calc(x, 1)));
    return 1;
}