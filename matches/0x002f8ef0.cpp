struct X {
    unsigned int a, b, c, d;
    unsigned char e;
    X* Init(unsigned int, unsigned int);
};
X* X::Init(unsigned int p, unsigned int q) {
    a = p;
    b = q;
    c = 0;
    d = 0;
    e = 1;
    return this;
}
