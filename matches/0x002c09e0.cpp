void Free(void*);
void* Alloc(int);
class Image32;
class Base {
  public:
    Base(const Image32& o);
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
    virtual void Copy(const Image32* s, int a, int b, int w, int h, int c, int d);
    char pad[0xc];
    int mW, mH, mBpp;
    char pad2[8];
    int* mData;
    char pad3[1];
    char mFlag;
};
class Image32 : public Base {
  public:
    Image32(const Image32& o);
    virtual void v0();
};
Image32::Image32(const Image32& o) : Base(o) {
    mBpp = 0x20;
    int h = o.mH;
    int w = o.mW;
    mW = w;
    mH = h;
    Free(mData);
    mData = (int*)Alloc(mH * mW * 4);
    char f = mFlag;
    mFlag = 0;
    Base* b = this;
    b->Copy(&o, 0, 0, o.mW, o.mH, 0, 0);
    mFlag = f;
}
