extern "C" bool __cdecl Check(const void*, const void*);
int __cdecl Target(const void* a, const char* b) {
    if (Check(a, b) && Check(a, b + 4) && Check(a, b + 8))
        return 1;
    return 0;
}