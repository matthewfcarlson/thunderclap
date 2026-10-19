class B_246f00;
class A_246f00 {
  public:
    char helper(int, int);
    B_246f00* mP;
    unsigned char mFlag;
    char f(int a, int b, char c, int d);
};
class B_246f00 {
  public:
    int pad[2];
    char (*mFn)(B_246f00*, int, int, int);
};
char A_246f00::f(int a, int b, char c, int d) {
    if (c && mFlag) {
        return helper(a, b);
    }
    B_246f00* p = mP;
    return p->mFn(p, a, b, d);
}
