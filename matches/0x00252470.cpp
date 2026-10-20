extern "C" unsigned char __cdecl FUN_00246f50(const char*, const char*, ...);
extern "C" unsigned char __cdecl FUN_0025abf0(const char**, const char*);
extern const char fmt[];
extern const char nl[];
unsigned char __cdecl FUN_00252470(const char** text, const char* value, const char** other) {
    const char* s = *text;
    if (FUN_00246f50(s, fmt, value)) {
        if (FUN_0025abf0(text, *other)) {
            value = *text;
            return FUN_00246f50(value, nl);
        }
    }
    return 0;
}