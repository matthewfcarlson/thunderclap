extern "C" double __cdecl FUN_00339ec0(int, int);
extern "C" void __cdecl FUN_00213340(int, float);
extern "C" double __cdecl sin(double);

extern "C" int __cdecl FUN_0033b640(int L) {
    FUN_00213340(L, (float)sin(FUN_00339ec0(L, 1)));
    return 1;
}
