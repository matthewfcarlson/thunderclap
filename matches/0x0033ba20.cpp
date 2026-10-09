extern "C" int __cdecl FUN_00339f70(int, int);
extern "C" double __cdecl FUN_00339ec0(int, int);
extern "C" float __cdecl FUN_00348010(double, int);
extern "C" void __cdecl FUN_00213340(int, float);

int FUN_0033ba20(int param_1) {
    int uVar1 = FUN_00339f70(param_1, 2);
    double d = FUN_00339ec0(param_1, 1);
    FUN_00213340(param_1, FUN_00348010(d, uVar1));
    return 1;
}
