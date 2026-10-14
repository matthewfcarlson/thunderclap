struct X_2f8ef0 {
    unsigned int a, b, c, d;
    unsigned char e;
    X_2f8ef0* Init(unsigned int, unsigned int);
};
X_2f8ef0* X_2f8ef0::Init(unsigned int p, unsigned int q) {
    a = p;
    b = q;
    c = 0;
    d = 0;
    e = 1;
    return this;
}
