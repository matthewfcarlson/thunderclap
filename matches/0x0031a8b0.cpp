struct T3 {
    unsigned int x, y, z;
};
struct X_31a8b0 {
    unsigned int a;
    T3 b;
    T3 c;
    unsigned int d[5];
    T3 e;
    unsigned int f[9];
    X_31a8b0& operator=(const X_31a8b0&);
};
X_31a8b0& X_31a8b0::operator=(const X_31a8b0& o_31a8b0) {
    a = o_31a8b0.a;
    b = o_31a8b0.b;
    c = o_31a8b0.c;
    d[0] = o_31a8b0.d[0];
    d[1] = o_31a8b0.d[1];
    d[2] = o_31a8b0.d[2];
    d[3] = o_31a8b0.d[3];
    d[4] = o_31a8b0.d[4];
    e = o_31a8b0.e;
    f[0] = o_31a8b0.f[0];
    f[1] = o_31a8b0.f[1];
    f[2] = o_31a8b0.f[2];
    f[3] = o_31a8b0.f[3];
    f[4] = o_31a8b0.f[4];
    f[5] = o_31a8b0.f[5];
    f[6] = o_31a8b0.f[6];
    f[7] = o_31a8b0.f[7];
    f[8] = o_31a8b0.f[8];
    return *this;
}