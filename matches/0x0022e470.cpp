struct M16 {
    float m[16];
};
struct V4_22e470 {
    int a, b, c, d;
};

class Foo_22e470 {
  public:
    Foo_22e470& Copy(const Foo_22e470& o);
    M16 m;
    V4_22e470 v0;
    V4_22e470 v1;
    V4_22e470 v2;
    V4_22e470 v3;
};

Foo_22e470& Foo_22e470::Copy(const Foo_22e470& o) {
    m = o.m;
    v0 = o.v0;
    v1 = o.v1;
    v2 = o.v2;
    v3 = o.v3;
    return *this;
}
