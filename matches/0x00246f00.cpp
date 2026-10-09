class B;
class A {
  public:
    void helper(int, int);
    B* mP;
    unsigned char mFlag;
    void f(int a, int b, char c, int d);
};
class B {
  public:
    int pad[2];
    void (*mFn)(B*, int, int, int);
};
void A::f(int a, int b, char c, int d) {
    if (c && mFlag) {
        helper(a, b);
        return;
    }
    B* p = mP;
    p->mFn(p, a, b, d);
}
