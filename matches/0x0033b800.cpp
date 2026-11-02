extern "C" float __cdecl getval(int, int);
extern "C" double __cdecl fmod(double, double);
extern "C" void __cdecl send(int, float);
extern "C" int __cdecl FUN_0033b800(int x) {
    float a = getval(x, 2);
    float b = getval(x, 1);
    send(x, (float)fmod(b, a));
    return 1;
}