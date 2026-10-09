extern "C" int __cdecl FUN_0021add0(void*, int, int, int);
extern "C" void __cdecl FUN_00217130(void*, int, int);
struct Pair {
    unsigned int a;
    unsigned int b;
};
extern "C" int __cdecl FUN_00219560(void* p1, int count, Pair* pair) {
    int size = count * 4 + 0x18;
    int r = FUN_0021add0(p1, 0, 0, size);
    FUN_00217130(p1, r, 6);
    *(char*)(r + 6) = 0;
    *(unsigned int*)(r + 0x10) = pair->a;
    *(unsigned int*)(r + 0x14) = pair->b;
    *(char*)(r + 7) = (char)count;
    if (count != 0) {
        unsigned int* p = (unsigned int*)r + count + 6;
        do {
            --p;
            --count;
            *p = 0;
        } while (count != 0);
    }
    return r;
}
