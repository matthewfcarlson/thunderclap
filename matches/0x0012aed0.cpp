extern "C" void* __cdecl alloc(unsigned int);
extern "C" void* g_TargetClearTrackVtable;
struct Obj_12aed0 {
    void* vptr;
    int pad;
    int x;
    int y;
    unsigned char z;
    void initBase();
};
Obj_12aed0* factory() {
    Obj_12aed0* p = (Obj_12aed0*)alloc(0x14);
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
