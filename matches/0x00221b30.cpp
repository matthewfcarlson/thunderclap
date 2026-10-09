struct P {
    int a[16];
};
struct Q {
    int a[4];
};
class X {
  public:
    P p;
    Q q;
    int c;
    void Copy(const X&);
};
void X::Copy(const X& other) {
    p = other.p;
    q = other.q;
    c = other.c;
}