struct S {
    unsigned short x[4];
    S* Copy(const S* src);
};
S* S::Copy(const S* src) {
    x[0] = src->x[0];
    x[1] = src->x[1];
    x[2] = src->x[2];
    x[3] = src->x[3];
    return this;
}
