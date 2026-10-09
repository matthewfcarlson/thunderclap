struct T3 {
    unsigned int x, y, z;
};
struct X {
    unsigned int a;
    T3 b;
    T3 c;
    unsigned int d[5];
    T3 e;
    unsigned int f[9];
    X& operator=(const X&);
};
X& X::operator=(const X& o) {
    a = o.a;
    b = o.b;
    c = o.c;
    d[0] = o.d[0];
    d[1] = o.d[1];
    d[2] = o.d[2];
    d[3] = o.d[3];
    d[4] = o.d[4];
    e = o.e;
    f[0] = o.f[0];
    f[1] = o.f[1];
    f[2] = o.f[2];
    f[3] = o.f[3];
    f[4] = o.f[4];
    f[5] = o.f[5];
    f[6] = o.f[6];
    f[7] = o.f[7];
    f[8] = o.f[8];
    return *this;
}