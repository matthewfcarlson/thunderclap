struct Sub_2c3930 {
    void Set(int);
    char p[8];
};
struct Base_2c3930 {
    Base_2c3930();
    virtual void h();
    int x;
    Sub_2c3930 s;
};
struct ILCC {
    virtual void f();
};
void* Alloc(unsigned);
struct TextBible : Base_2c3930, ILCC {
    virtual void g();
    int* mBegin;
    int* mEnd;
    int* mCap;
    int pad2;
    short mA;
    short mB;
    TextBible(int a, int n);
};
TextBible::TextBible(int a, int n) {
    mBegin = 0;
    mEnd = 0;
    mCap = 0;
    mA = -1;
    mB = 0;
    if (a)
        s.Set(a);
    if (n) {
        mBegin = (int*)Alloc(n * 4);
        if (mBegin) {
            mCap = mBegin + n;
            mEnd = mBegin;
            return;
        }
    } else
        mBegin = 0;
    mEnd = 0;
    mCap = 0;
}