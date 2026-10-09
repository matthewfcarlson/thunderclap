typedef unsigned int u32;
struct d3dPrimBuffer {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual u32 vfunc_7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[0x28];
    void* member;
    char pad2[5];
    unsigned char flag;
};
extern void FUN_0031c230(int);
u32 d3dPrimBuffer::vfunc_7() {
    u32 result = *(u32*)((char*)member + 4);
    FUN_0031c230(0);
    flag = 1;
    return result;
}