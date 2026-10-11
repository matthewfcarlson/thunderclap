extern "C" char DAT_004cdb4c[];
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern "C" void* __cdecl FUN_002703c0(void* dst, unsigned int a2, const void* src, unsigned int a4,
                                      unsigned int n) {
    memcpy(dst, src, n);
    return (void*)((int)DAT_004cdb4c);
}