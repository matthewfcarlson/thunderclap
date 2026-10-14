extern "C" char DAT_0040ebb0[];
typedef unsigned int u32_11b4c0;
void* __cdecl alloc(unsigned int);
struct Obj_11b4c0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* f();
    void initialize();
};
void* Obj_11b4c0::f() {
    Obj_11b4c0* p = (Obj_11b4c0*)alloc(0x2c);
    if (p != 0) {
        p->initialize();
        *(u32_11b4c0*)((char*)p + 0x0c) = 0;
        *(u32_11b4c0*)((char*)p + 0x14) = 0;
        *(u32_11b4c0*)((char*)p + 0x18) = 0;
        *(u32_11b4c0*)((char*)p + 0x1c) = 0;
        *(u32_11b4c0*)((char*)p + 0x20) = 0;
        *(u32_11b4c0*)((char*)p + 0x28) = 0;
        *(u32_11b4c0*)p = ((int)DAT_0040ebb0);
        *(u32_11b4c0*)((char*)p + 0x10) = 0xbf800000;
        *(u32_11b4c0*)((char*)p + 0x24) = 0x3f800000;
        return p;
    }
    return 0;
}