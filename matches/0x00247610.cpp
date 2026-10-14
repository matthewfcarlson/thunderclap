struct Tmp_247610 {
    char pad[0x48];
    Tmp_247610* init(void*, void*, unsigned, unsigned);
    void cleanup();
};
struct Alloc_247610 {
    void*(__cdecl* f0)();
    void*(__cdecl* alloc)(Alloc_247610*, Tmp_247610*);
};
extern Alloc_247610* gAlloc_247610;
extern char gA_247610, gB;
void* __cdecl FUN_00247610(int a, int b, unsigned size, unsigned align) {
    if (!(size > 0))
        return 0;
    if (align <= 8)
        align = 8;
    size += align;
    Tmp_247610 t;
    Tmp_247610* ptr = t.init(&gA_247610, &gB, size, align);
    char* p = (char*)gAlloc_247610->alloc(gAlloc_247610, ptr);
    t.cleanup();
    char* q = p + align;
    *(unsigned*)(q - 4) = align;
    *(unsigned*)(q - 8) = size;
    return q;
}