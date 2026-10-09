class ShadowSkin {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual ShadowSkin* vfunc_4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    void Init(ShadowSkin*);
};
extern void* __cdecl alloc(int);
ShadowSkin* ShadowSkin::vfunc_4() {
    ShadowSkin* q = (ShadowSkin*)alloc(0x58);
    if (q) {
        q->Init(this);
        *(int*)q = 0x42fa64;
        return q;
    }
    return 0;
}