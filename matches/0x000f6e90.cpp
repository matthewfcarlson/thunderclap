struct S {
    unsigned int a[6];
    S& operator=(const S& src);
};
S& S::operator=(const S& src) {
    a[0] = src.a[0];
    a[1] = src.a[1];
    a[2] = src.a[2];
    a[3] = src.a[3];
    a[4] = src.a[4];
    a[5] = src.a[5];
    return *this;
}
