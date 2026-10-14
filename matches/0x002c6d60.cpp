struct S_2c6d60 {
    unsigned short x[4];
    S_2c6d60* Copy(const S_2c6d60* src);
};
S_2c6d60* S_2c6d60::Copy(const S_2c6d60* src) {
    x[0] = src->x[0];
    x[1] = src->x[1];
    x[2] = src->x[2];
    x[3] = src->x[3];
    return this;
}
