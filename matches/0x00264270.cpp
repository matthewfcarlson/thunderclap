class Inner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int, int);
};
class Obj {
  public:
    char p[8];
    Inner* mInner;
    char q[8];
    int mCount;
    char r[4];
    void FUN_002640f0();
    void FUN_00264140(int, int, int);
    bool fnB(int, int, int, int);
};
bool Obj::fnB(int a, int b, int c, int d) {
    int n = b * c;
    mInner->f3(a, n, d);
    mCount += n;
    FUN_002640f0();
    FUN_00264140(a, b, c);
    return true;
}
