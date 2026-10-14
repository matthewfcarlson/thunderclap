struct X {
    int a, b;
    X* copy(X* p);
};
X* X::copy(X* p) {
    a = p->a;
    b = p->b;
    return this;
}
