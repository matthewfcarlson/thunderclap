struct Parser;
const char* __cdecl FUN_002611b0(Parser* p);
float __cdecl FUN_00260d00(const char* text);
const char* __cdecl FUN_002616d0(Parser* p) {
    const char* a = FUN_002611b0(p);
    const char* b = FUN_002611b0(p);
    float fa = FUN_00260d00(a);
    float fb = FUN_00260d00(b);
    return (fa >= fb) ? "t" : "nil";
}