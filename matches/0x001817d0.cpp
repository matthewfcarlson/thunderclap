typedef unsigned int u32_1817d0;
struct ThisCall_00035ef0 {
    u32_1817d0 FUN_00035ef0(int);
};
u32_1817d0 __cdecl FUN_001817d0(void* p, int n) {
    if (p) {
        if (n < 0)
            return *(u32_1817d0*)((char*)p + 0x128);
        if (n < 8)
            return ((ThisCall_00035ef0*)(p))->FUN_00035ef0(n);
    }
    return 0;
}