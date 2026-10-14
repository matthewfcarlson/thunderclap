// Same code shape as 0x00221b30 (propagated; names are from that function)
struct P_221be0 {
    int a[16];
};
struct Q_221be0 {
    int a[4];
};
class X_221be0 {
  public:
    P_221be0 p;
    Q_221be0 q;
    int c;
    void Copy(const X_221be0&);
};
void X_221be0::Copy(const X_221be0& other) {
    p = other.p;
    q = other.q;
    c = other.c;
}