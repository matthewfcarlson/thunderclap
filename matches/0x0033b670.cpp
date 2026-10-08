extern "C" long double __cdecl FUN_00339ec0(unsigned int, int);
extern "C" void __cdecl FUN_00213340(unsigned int, float);
extern "C" double __cdecl cos(double);
extern "C" int __cdecl FUN_0033b670(unsigned int x) {
    long double a = FUN_00339ec0(x, 1);
    FUN_00213340(x, (float)cos((double)a));
    return 1;
}
