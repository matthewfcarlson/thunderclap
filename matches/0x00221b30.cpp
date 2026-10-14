struct P_221b30 {
    int a[16];
};
struct Q_221b30 {
    int a[4];
};
class X_221b30 {
  public:
    P_221b30 p;
    Q_221b30 q;
    int c;
    void Copy(const X_221b30&);
};
void X_221b30::Copy(const X_221b30& other) {
    p = other.p;
    q = other.q;
    c = other.c;
}