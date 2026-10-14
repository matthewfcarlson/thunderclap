typedef void*(__cdecl* AllocFn)(void*, int, int);
struct Manager_2eb780 {
    char pad[0x20];
    AllocFn alloc;
    char pad24[4];
    void* context;
};
void __cdecl FUN_002eb780(unsigned char a, unsigned char b, int c, int d, Manager_2eb780* m) {
    char* p = (char*)m->alloc(m->context, 1, 0x1c);
    if (p) {
        p[0x10] = a;
        p[0x11] = b;
        *(int*)p = 0;
        *(int*)(p + 0x14) = c;
        *(int*)(p + 0x18) = d;
    }
}