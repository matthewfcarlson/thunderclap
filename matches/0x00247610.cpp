struct Tmp {
    char pad[0x48];
    Tmp* init(void*, void*, unsigned, unsigned);
    void cleanup();
};
struct Alloc {
    void*(__cdecl* f0)();
    void*(__cdecl* alloc)(Alloc*, Tmp*);
};
extern Alloc* gAlloc;
extern char gA, gB;
void* __cdecl FUN_00247610(int a, int b, unsigned size, unsigned align) {
    if (!(size > 0))
        return 0;
    if (align <= 8)
        align = 8;
    size += align;
    Tmp t;
    Tmp* ptr = t.init(&gA, &gB, size, align);
    char* p = (char*)gAlloc->alloc(gAlloc, ptr);
    t.cleanup();
    char* q = p + align;
    *(unsigned*)(q - 4) = align;
    *(unsigned*)(q - 8) = size;
    return q;
}