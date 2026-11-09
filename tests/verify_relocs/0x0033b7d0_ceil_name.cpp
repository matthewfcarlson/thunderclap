// verify_relocs regression (libname1): math.floor as it was before 741fd13b2, calling floor (0x0034557c) under
// the name __ceil_default (0x003481ba). The byte match masks the call; libname_address_mismatch must flag it.
extern "C" double __cdecl FUN_00339ec0(int, int);
extern "C" double __cdecl __ceil_default(double);
extern "C" void __cdecl FUN_00213340(int, float);
extern "C" int __cdecl FUN_0033b7d0(int L) {
    double x = FUN_00339ec0(L, 1);
    double y = __ceil_default(x);
    FUN_00213340(L, (float)y);
    return 1;
}
