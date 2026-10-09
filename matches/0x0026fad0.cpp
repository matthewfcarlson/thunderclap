namespace core {
class Drive {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual int vfunc_19(int* a, int b);
    char pad[0xb4 - 4];
    int mErr;
    int Helper(int b, int* buf, int* c);
};
int __stdcall Conv(int a, int* b);
} // namespace core

int core::Drive::vfunc_19(int* a, int b) {
    int t;
    char buf[0x140];
    int v = *a;
    if (v == -1) {
        mErr = 1;
        return 0;
    }
    if (core::Conv(v, (int*)buf) == 0) {
        t = -1;
        mErr = Helper(b, (int*)buf, &t);
    } else {
        mErr = Helper(b, (int*)buf, a);
    }
    return mErr == 0;
}
