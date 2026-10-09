extern "C" void* __cdecl alloc(unsigned int);
extern "C" void* g_TargetClearTrackVtable;
struct Obj {
    void* vptr;
    int pad;
    int x;
    int y;
    unsigned char z;
    void initBase();
};
Obj* factory() {
    Obj* p = (Obj*)alloc(0x14);
    if (p) {
        p->initBase();
        p->vptr = &g_TargetClearTrackVtable;
        p->y = 0;
        p->z = 0;
        p->x = 1;
        return p;
    }
    return 0;
}
