float __cdecl FUN_00339ec0(int, int);
extern "C" double __cdecl acos(double);
void __cdecl FUN_00213340(int, float);
int __cdecl FUN_0033b700(int value) {
    float a = FUN_00339ec0(value, 1);
    FUN_00213340(value, (float)acos(a));
    return 1;
}