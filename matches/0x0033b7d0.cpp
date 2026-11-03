// Same code shape as 0x0033b7a0 (propagated; names are from that function)
extern "C" double __cdecl FUN_00339ec0(int, int);
extern "C" double __cdecl __ceil_default(double);
extern "C" void __cdecl FUN_00213340(int, float);
extern "C" int __cdecl FUN_0033b7d0(int L) {
    double x = FUN_00339ec0(L, 1);
    double y = __ceil_default(x);
    FUN_00213340(L, (float)y);
    return 1;
}
