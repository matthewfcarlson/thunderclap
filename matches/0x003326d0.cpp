struct Dev {
    char p0[0x20];
    int tc;
    char p1[0xc0];
    int s;
    char p2[0x14];
    int t;
};
extern unsigned int g_dirty;
extern int g_a;
extern int g_b;
void __stdcall SetTC(int a, int b);
class Sub {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
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
    virtual void Set(int x);
};
class S {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0xc];
    Sub* sub;
    Dev* dev;
};
void S::v13() {
    if (dev->s != 1) {
        dev->s = 1;
        g_dirty |= 0x800;
        g_a = 1;
    }
    if (dev->tc != 2) {
        dev->tc = 2;
        SetTC(2, 2);
    }
    if (dev->t != 0) {
        dev->t = 0;
        g_dirty |= 0x400;
        g_b = 0;
    }
    sub->Set(3);
}
