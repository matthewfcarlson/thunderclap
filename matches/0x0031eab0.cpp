struct Four_31eab0 {
    int x_31eab0, y, z, w;
};
class C_31eab0 {
  public:
    int v, a, b, c, d;
    Four_31eab0 e;
    Four_31eab0 f;
    C_31eab0& operator=(const C_31eab0&);
};
C_31eab0& C_31eab0::operator=(const C_31eab0& x_31eab0) {
    a = x_31eab0.a;
    b = x_31eab0.b;
    c = x_31eab0.c;
    d = x_31eab0.d;
    e = x_31eab0.e;
    f = x_31eab0.f;
    return *this;
}