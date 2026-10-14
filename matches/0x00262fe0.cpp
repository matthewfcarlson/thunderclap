struct Dev_262fe0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Read(int a, unsigned n, int b);
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
    virtual void Sync(unsigned* g);
};
void G1(unsigned*, int);
void G2(unsigned*);
void G3(unsigned*);
class HalRsdFileStream {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned vfunc_7(int a, int b, unsigned n);
    char pad[0x20 - 4];
    Dev_262fe0* mDev;
    char pad2[0x2c - 0x24];
    unsigned mAvail;
    char pad3[0x3c - 0x30];
    unsigned mLen;
};
unsigned HalRsdFileStream::vfunc_7(int a, int b, unsigned n) {
    if (mAvail < n)
        mLen = mAvail;
    else
        mLen = n;
    if (mLen > 0) {
        G1(&n, 0);
        mDev->Read(a, mLen, b);
        mDev->Sync(&n);
        G2(&n);
        G3(&n);
    }
    return mLen;
}
