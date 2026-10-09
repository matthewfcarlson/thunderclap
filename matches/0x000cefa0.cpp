class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class HUDOverlay {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void run(unsigned char, float);
};
class Method2 : public Function {
  public:
    virtual void vfunc_2(void* a, void* p, void* c);
    char pad[0x18];
    void (HUDOverlay::*mFn)(unsigned char, float);
};
void Method2::vfunc_2(void* a, void* p, void* c) {
    HUDOverlay* h = (HUDOverlay*)a;
    (h->*mFn)(*(unsigned char*)p, *(float*)((char*)p + 4));
}
