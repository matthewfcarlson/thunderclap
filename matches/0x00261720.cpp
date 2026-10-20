extern void* __cdecl FUN_002611b0(void*);
extern float __cdecl FUN_00260d00(void*);
extern char DAT_004269b4[], DAT_00429b50[];
const char* __cdecl FUN_00261720(void* value) {
    void* first = FUN_002611b0(value);
    void* second = FUN_002611b0(value);
    float left = FUN_00260d00(first);
    float right = FUN_00260d00(second);
    return left <= right ? DAT_00429b50 : DAT_004269b4;
}