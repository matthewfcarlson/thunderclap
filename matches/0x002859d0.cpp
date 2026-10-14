extern const float gOne_2859d0;
extern const float gZero_2859d0;
struct SimpleFrameController {
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
    virtual void vfunc_23();
    char pad[0x18 - 4];
    unsigned long m18;
    unsigned long m1c;
    unsigned long m20;
    unsigned long m24;
    unsigned long m28;
    unsigned long m2c;
    float m30;
    unsigned long m34;
    unsigned char m38[4];
    void* m3c;
};
void SimpleFrameController::vfunc_23() {
    m20 = 0;
    m24 = 0;
    m2c = 0;
    float f;
    if (m3c == 0)
        f = gZero_2859d0;
    else {
        f = *(float*)((char*)m3c + 0x10) - gOne_2859d0;
        if (f < gZero_2859d0)
            f = gZero_2859d0;
    }
    m30 = f;
    m34 = 0;
    m28 = 0x7f7fffff;
    m38[0] = 1;
    m18 = 0x3f800000;
}