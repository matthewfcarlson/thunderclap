typedef unsigned int u32;
void* __cdecl alloc(unsigned int);
struct Obj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* f();
    void initialize();
};
void* Obj::f() {
    Obj* p = (Obj*)alloc(0x2c);
    if (p != 0) {
        p->initialize();
        *(u32*)((char*)p + 0x0c) = 0;
        *(u32*)((char*)p + 0x14) = 0;
        *(u32*)((char*)p + 0x18) = 0;
        *(u32*)((char*)p + 0x1c) = 0;
        *(u32*)((char*)p + 0x20) = 0;
        *(u32*)((char*)p + 0x28) = 0;
        *(u32*)p = 0x40ebb0;
        *(u32*)((char*)p + 0x10) = 0xbf800000;
        *(u32*)((char*)p + 0x24) = 0x3f800000;
        return p;
    }
    return 0;
}