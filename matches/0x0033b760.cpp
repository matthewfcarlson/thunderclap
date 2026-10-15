extern "C" double atan2(double, double);
extern "C" float __cdecl GetVal(int, int);
extern "C" void __cdecl SetVal(int, float);
int __cdecl Target(int x) {
    float a = GetVal(x, 2);
    float b = GetVal(x, 1);
    SetVal(x, (float)atan2(b, a));
    return 1;
}