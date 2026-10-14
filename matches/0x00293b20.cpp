struct H {
    void init();
    void combine(void*, void*);
    void finish();
};
struct M_293b20 {
    unsigned int v[16];
};
class VectorCamera {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
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
    virtual void a25();
    virtual void vfunc_26();
    char pad[0xdc - 4];
};
void VectorCamera::vfunc_26() {
    char* b = (char*)this;
    ((H*)(b + 0xdc))->init();
    ((H*)(b + 0xe8))->init();
    ((H*)(b + 0x8c))->combine(b + 0xdc, b + 0xe8);
    *(volatile int*)(b + 0xbc) = *(volatile int*)(b + 0xd0);
    *(volatile int*)(b + 0xc0) = *(volatile int*)(b + 0xd4);
    *(volatile int*)(b + 0xc4) = *(volatile int*)(b + 0xd8);
    *(M_293b20*)(b + 0x4c) = *(M_293b20*)(b + 0x8c);
    ((H*)(b + 0x4c))->finish();
    b[0xcc] = 1;
}