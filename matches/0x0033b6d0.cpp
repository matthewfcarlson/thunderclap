extern "C" double asin(double);
float __cdecl FUN_00339ec0(int L, int narg);
void __cdecl FUN_00213340(int L, float n);
int __cdecl FUN_0033b6d0(int L) {
    float x = FUN_00339ec0(L, 1);
    *(volatile float*)&x = x;
    FUN_00213340(L, (float)asin(x));
    return 1;
}