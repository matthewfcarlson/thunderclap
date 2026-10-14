typedef unsigned int u32_33b8d0;
extern float __cdecl FUN_00339ec0(u32_33b8d0, int);
extern void __cdecl FUN_00213340(u32_33b8d0, float);
extern "C" double __cdecl log(double);
int __cdecl target(u32_33b8d0 param_1) {
    FUN_00213340(param_1, (float)log((double)FUN_00339ec0(param_1, 1)));
    return 1;
}
