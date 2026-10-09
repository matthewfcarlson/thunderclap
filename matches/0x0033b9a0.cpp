// Same code shape as 0x0033b970 (propagated; names are from that function)
extern "C" float __cdecl FUN_00339ec0(void*, int);
extern "C" void __cdecl FUN_00213340(void*, float);
extern const float gScale;
int __cdecl FUN_0033b970(void* param_1) {
    FUN_00213340(param_1, FUN_00339ec0(param_1, 1) * gScale);
    return 1;
}