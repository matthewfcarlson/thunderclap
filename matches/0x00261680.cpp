extern "C" void* __cdecl FUN_002611b0(void*);
extern "C" float __cdecl FUN_00260d00(void*);
extern char DAT_00429b50, DAT_004269b4;
const char* __cdecl FUN_00261680(void* value) {
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float firstValue = FUN_00260d00(first);
    float secondValue = FUN_00260d00(second);
    return firstValue < secondValue ? &DAT_00429b50 : &DAT_004269b4;
}