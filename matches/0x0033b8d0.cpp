typedef unsigned int u32_33b8d0;
extern float __cdecl FUN_00339ec0(u32_33b8d0, int);
extern void __cdecl FUN_00213340(u32_33b8d0, float);
extern "C" double __cdecl log(double);
extern "C" int __cdecl FUN_0033b8d0(u32_33b8d0 L) {
    FUN_00213340(L, (float)log((double)FUN_00339ec0(L, 1)));
    return 1;
}
