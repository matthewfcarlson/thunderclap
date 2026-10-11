typedef unsigned char byte;
struct O {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
    virtual void f();
    virtual void g();
};
struct T {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    char pad[0x10];
    int count;
};
struct Drive {
    virtual Drive* vfunc_0(byte);
    char pad[4];
    T* field8;
};
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
extern O* glob;
Drive* Drive::vfunc_0(byte flag) {
    *(void**)this = (void*)0x42b9bc;
    ((O*)((char*)field8 + 4))->a();
    field8->count--;
    ((O*)((char*)field8 + 4))->b();
    ((O*)field8)->b();
    *(void**)this = (void*)0x42b914;
    if (flag & 1) {
        FUN_0026d850((void*)0x52a1c8);
        glob->e(this);
        FUN_0026d840((void*)0x52a1c8);
    }
    return this;
}
