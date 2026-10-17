extern "C" double __cdecl FUN_00339ec0(void*, int);
extern "C" void __cdecl FUN_00213340(void*, float);
extern "C" double __cdecl atan(double);
int __cdecl FUN_0033b730(void* object) {
    double angle = FUN_00339ec0(object, 1);
    FUN_00213340(object, (float)atan(angle));
    return 1;
}
