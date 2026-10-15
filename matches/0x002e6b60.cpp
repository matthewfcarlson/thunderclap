extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __cdecl FUN_002e6b60(int unused, void* dst, int value, unsigned int n) {
    return memset(dst, value, n);
}