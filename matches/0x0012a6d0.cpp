extern "C" char DAT_0040fdf4[];
extern void* __cdecl alloc(unsigned int);
struct Target {
    unsigned int vt;
    unsigned int a;
    unsigned int b;
    unsigned int zero;
    float angle;
};
struct Init {
    void initialize(int);
};
struct Factory {
    Target* vfunc_5();
};
Target* Factory::vfunc_5() {
    Target* p = (Target*)alloc(0x14);
    if (p) {
        ((Init*)p)->initialize(0);
        p->vt = ((int)DAT_0040fdf4);
        p->zero = 0;
        p->angle = 3.1415927f;
        return p;
    }
    return 0;
}