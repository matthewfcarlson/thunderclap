struct R {
    char p[0x18];
    float lo, hi, lo2, hi2;
};
struct T {
    char p[0x1c];
    R* r;
    char p20[4];
    float m24, m28, m2c;
    bool f();
};
bool T::f() {
    bool a = m28 <= r->hi && m28 >= r->lo;
    bool b = m2c <= r->hi2 && m2c >= r->lo2;
    union {
        float f;
        unsigned i;
    } u;
    u.f = m24;
    u.i &= 0x7fffffff;
    bool c = u.f <= 1e-05f;
    return a && b && c;
}
