// Same code shape as 0x0033b7a0 (propagated; names are from that function)
extern "C" double __cdecl FUN_00339ec0(int, int);
extern "C" double __cdecl __ceil_default(double);
extern "C" void __cdecl FUN_00213340(int, float);
extern "C" int __cdecl target(int param_1) {
    double x = FUN_00339ec0(param_1, 1);
    double y = __ceil_default(x);
    FUN_00213340(param_1, (float)y);
    return 1;
}
