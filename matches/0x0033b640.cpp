extern "C" double __cdecl FUN_00339ec0(int, int);
extern "C" void __cdecl FUN_00213340(int, float);
extern "C" double __cdecl sin(double);

int __cdecl target(int param_1) {
    FUN_00213340(param_1, (float)sin(FUN_00339ec0(param_1, 1)));
    return 1;
}
