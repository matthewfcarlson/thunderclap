extern "C" unsigned int __cdecl strlen(const char*);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" char* __cdecl FUN_000f6610(const char* s) {
    if (s) {
        unsigned int n = strlen(s) + 1;
        char* d = (char*)malloc(n);
        if (!d)
            return 0;
        memcpy(d, s, n);
        return d;
    }
    return 0;
}