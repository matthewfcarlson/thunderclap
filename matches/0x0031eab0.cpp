struct Four {
    int x, y, z, w;
};
class C {
  public:
    int v, a, b, c, d;
    Four e;
    Four f;
    C& operator=(const C&);
};
C& C::operator=(const C& x) {
    a = x.a;
    b = x.b;
    c = x.c;
    d = x.d;
    e = x.e;
    f = x.f;
    return *this;
}