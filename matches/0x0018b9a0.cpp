// Same code shape as 0x0018b6f0 (propagated; names are from that function)
typedef unsigned int u32_18b9a0;
void* __cdecl alloc(unsigned int);
struct InitObj_18b9a0 {
    void init(int);
};
extern int vtable_18b9a0;
struct Factory_18b9a0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void* f();
};
void* Factory_18b9a0::f() {
    char* p = (char*)alloc(0x14);
    if (p) {
        ((InitObj_18b9a0*)p)->init(0);
        *(u32_18b9a0*)p = (u32_18b9a0)&vtable_18b9a0;
        *(u32_18b9a0*)(p + 0xc) = 0xffffffff;
        p[0x10] = 1;
        return p;
    }
    return 0;
}