extern "C" char DAT_00413678[];
typedef unsigned int u32_14c030;
struct GrappleStruggleTrack {
    u32_14c030 a0, a4, a8, ac, a10, a14, a18, a1c, a20;
    void initialize();
};
void* __cdecl alloc(unsigned int);
struct Factory_14c030 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* make();
};
void* Factory_14c030::make() {
    GrappleStruggleTrack* p = (GrappleStruggleTrack*)alloc(0x24);
    if (p) {
        p->initialize();
        p->ac = 0;
        p->a14 = 0;
        p->a18 = 0;
        p->a1c = 0;
        p->a20 = 0;
        p->a0 = ((int)DAT_00413678);
        p->a10 = 0xbf800000;
        p->a8 = 1;
        return p;
    }
    return 0;
}
