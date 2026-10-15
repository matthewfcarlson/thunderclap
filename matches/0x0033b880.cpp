extern "C" float __cdecl sample(int, int);
extern "C" double __cdecl pow(double, double);
extern "C" void __cdecl output(int, float);
int __cdecl FUN_0033b880(int a) {
    float x = sample(a, 2);
    float y = sample(a, 1);
    output(a, (float)pow(y, x));
    return 1;
}