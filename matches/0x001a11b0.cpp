typedef unsigned int u32_1a11b0;
struct Track {
    char x[0x148];
    u32_1a11b0 Init();
};
struct Factory_1a11b0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual u32_1a11b0 f();
};
void* operator new(unsigned int);
u32_1a11b0 Factory_1a11b0::f() {
    Track* p = (Track*)::operator new(0x148);
    if (p)
        return p->Init();
    return 0;
}