typedef unsigned int uint;
extern "C" long double __cdecl FUN_00339ec0(uint, int);
extern "C" void __cdecl FUN_00213340(uint, float);
extern "C" double __cdecl tan(double);
int __cdecl target(uint a) {
    FUN_00213340(a, (float)tan((double)FUN_00339ec0(a, 1)));
    return 1;
}
