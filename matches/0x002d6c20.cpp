extern "C" void * __cdecl FUN_002e6c00(unsigned int, unsigned int);
extern "C" void * __cdecl memset(void *, int, unsigned int);
unsigned int * __cdecl FUN_002d6c20(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int n = b * c;
    unsigned int *p = (unsigned int *)FUN_002e6c00(a, n);
    if (n > 0x8000) {
        memset(p, 0, 0x8000);
        memset((char *)p + 0x8000, 0, n - 0x8000);
    } else memset(p, 0, n);
    return p;
}