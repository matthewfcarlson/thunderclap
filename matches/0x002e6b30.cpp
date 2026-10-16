extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl FUN_002e6b30(void* unused, void* dst, const void* src, unsigned int n) {
    return memcpy(dst, src, n);
}