extern "C" double __cdecl getval(void*, int);
extern "C" double __cdecl frexp(double, int*);
extern "C" void __cdecl putval(void*, float);
int __cdecl FUN_0033b9d0(void* p) {
    int exponent;
    double x = getval(p, 1);
    putval(p, (float)frexp(x, &exponent));
    putval(p, (float)exponent);
    return 2;
}