typedef unsigned int uint_33b6a0;
extern "C" long double __cdecl FUN_00339ec0(uint_33b6a0, int);
extern "C" void __cdecl FUN_00213340(uint_33b6a0, float);
extern "C" double __cdecl tan(double);
int __cdecl target(uint_33b6a0 a) {
    FUN_00213340(a, (float)tan((double)FUN_00339ec0(a, 1)));
    return 1;
}
