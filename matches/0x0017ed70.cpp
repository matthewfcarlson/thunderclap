extern void* __cdecl alloc(unsigned int);
struct Track {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    char pad[4];
    int x;
    int y;
    unsigned char z;
};
extern void __fastcall init(Track*);
struct Factory {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Track* vfunc_5();
};
Track* Factory::vfunc_5() {
    Track* p = (Track*)alloc(0x14);
    if (p) {
        init(p);
        p->z = 1;
        p->x = 1;
        *(unsigned int*)p = 0x417d48;
        p->y = 0;
        return p;
    }
    return 0;
}