class B_246f00;
class A_246f00 {
  public:
    void helper(int, int);
    B_246f00* mP;
    unsigned char mFlag;
    void f(int a, int b, char c, int d);
};
class B_246f00 {
  public:
    int pad[2];
    void (*mFn)(B_246f00*, int, int, int);
};
void A_246f00::f(int a, int b, char c, int d) {
    if (c && mFlag) {
        helper(a, b);
        return;
    }
    B_246f00* p = mP;
    p->mFn(p, a, b, d);
}
