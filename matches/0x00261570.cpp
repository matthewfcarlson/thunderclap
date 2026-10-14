extern "C" int strcmp(const char*, const char*);
extern "C" const char* __cdecl FUN_002611b0(const char*);
extern const char a[];
extern const char b[];
const char* __cdecl FUN_00261570(const char* s) {
    const char* x = FUN_002611b0(s);
    const char* y = FUN_002611b0(s);
    return strcmp(x, y) == 0 ? a : b;
}