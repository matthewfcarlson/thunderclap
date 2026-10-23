typedef unsigned int u32_33b8d0;
extern float __cdecl FUN_00339ec0(u32_33b8d0, int);
extern void __cdecl FUN_00213340(u32_33b8d0, float);
extern "C" double __cdecl log(double);
int __cdecl target(u32_33b8d0 param_1) {
    float v = FUN_00339ec0(param_1, 1);
    // WRONG: log of the magnitude; the original takes log of a negative value (NaN, the x87's invalid result)
    FUN_00213340(param_1, (float)log((double)(v < 0.0f ? -v : v)));
    return 1;
}
