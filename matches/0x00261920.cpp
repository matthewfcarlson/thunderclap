extern "C" char* __cdecl FUN_002611b0(char*);
extern "C" float __cdecl FUN_00260d00(char*);
extern "C" void __cdecl FUN_00260be0(char*, float);
void __cdecl FUN_00261920(char* s) {
    float x = FUN_00260d00(FUN_002611b0(s));
    char* p = FUN_002611b0(s);
    while (*p) {
        x *= FUN_00260d00(p);
        p = FUN_002611b0(s);
    }
    FUN_00260be0(s, x);
}