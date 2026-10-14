typedef unsigned int u32_2928e0;
struct Receiver_2928e0 {
    void f(u32_2928e0);
};
struct Camera {
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
    virtual void a11(void*, void*);
    virtual void vfunc_12(void*, Receiver_2928e0*);
    virtual void a13();
    virtual u32_2928e0 a14();
};
void Camera::vfunc_12(void* p2, Receiver_2928e0* p3) {
    a11(p2, p3);
    u32_2928e0 x = a14();
    p3->f(x);
}