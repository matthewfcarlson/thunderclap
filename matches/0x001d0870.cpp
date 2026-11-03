extern void* __cdecl FUN_00213d30(void*, unsigned int);
extern void __cdecl FUN_00338f30(void*, const char*);
extern void __cdecl FUN_002138e0(void*, int);

int __cdecl FUN_001d0870(void* L, unsigned int* vec) {
    unsigned int* dst = (unsigned int*)FUN_00213d30(L, 0xc);
    FUN_00338f30(L, "Vector");
    FUN_002138e0(L, -2);
    dst[0] = vec[0];
    dst[1] = vec[1];
    dst[2] = vec[2];
    return 1;
}