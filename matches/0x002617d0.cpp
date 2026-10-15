extern "C" char* __cdecl FUN_002611b0(const char*);
extern "C" float __cdecl FUN_00260d00(const char*);
extern "C" void __cdecl FUN_00260be0(const char*, float);
void __cdecl FUN_002617d0(const char* s) {
    float v = FUN_00260d00(FUN_002611b0(s));
    char* p = FUN_002611b0(s);
    while (*p) {
        v -= FUN_00260d00(p);
        p = FUN_002611b0(s);
    }
    FUN_00260be0(s, v);
}