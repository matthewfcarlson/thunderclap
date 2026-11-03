extern "C" int __cdecl FUN_00339f70(int, int);
extern "C" double __cdecl FUN_00339ec0(int, int);
extern "C" float __cdecl FUN_00348010(double, int);
extern "C" void __cdecl FUN_00213340(int, float);

extern "C" int FUN_0033ba20(int L) {
    int exponent = FUN_00339f70(L, 2);
    double d = FUN_00339ec0(L, 1);
    FUN_00213340(L, FUN_00348010(d, exponent));
    return 1;
}
