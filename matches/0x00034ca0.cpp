struct Vec4 {
    int a, b, c, d;
    Vec4& operator=(const Vec4&);
};
Vec4& Vec4::operator=(const Vec4& x) {
    a = x.a;
    b = x.b;
    c = x.c;
    d = x.d;
    return *this;
}