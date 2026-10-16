struct A {
    int a, b, c, d;
};
struct X {
    A v;
    X(const X& x);
};
X::X(const X& x) {
    v = x.v;
}