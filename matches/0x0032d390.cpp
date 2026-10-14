// Same code shape as 0x0032aa30 (propagated; names are from that function)
typedef unsigned char u8_32d390;
struct Ref_32d390 {
    virtual void f0();
    virtual void f1();
};
struct Helper_32d390 {
    void run();
};
extern void thunk_FUN_00267090(void*);
int shader_vtable;
struct pure3d_d3dSimpleShader_32d390 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual pure3d_d3dSimpleShader_32d390* vfunc_3(u8_32d390);
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    char pad[0x80 - sizeof(void*)];
    Ref_32d390* member;
};
pure3d_d3dSimpleShader_32d390* pure3d_d3dSimpleShader_32d390::vfunc_3(u8_32d390 destroy) {
    *(int**)this = &shader_vtable;
    if (member)
        member->f1();
    ((Helper_32d390*)this)->run();
    if (destroy & 1)
        thunk_FUN_00267090(this);
    return this;
}