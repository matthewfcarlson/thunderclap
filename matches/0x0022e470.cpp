struct M16 {
    float m[16];
};
struct V4 {
    int a, b, c, d;
};

class Foo {
  public:
    Foo& Copy(const Foo& o);
    M16 m;
    V4 v0;
    V4 v1;
    V4 v2;
    V4 v3;
};

Foo& Foo::Copy(const Foo& o) {
    m = o.m;
    v0 = o.v0;
    v1 = o.v1;
    v2 = o.v2;
    v3 = o.v3;
    return *this;
}
