struct X_1e9000 {
    int a, b;
    X_1e9000* copy(X_1e9000* p);
};
X_1e9000* X_1e9000::copy(X_1e9000* p) {
    a = p->a;
    b = p->b;
    return this;
}
