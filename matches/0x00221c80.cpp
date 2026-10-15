struct X {
    int a, b, c;
    char pad0[4];
    int d, e, f;
    char pad1[4];
    int g, h, i;
    char pad2[36];
    int state;
    void Copy(const X* p);
};
void X::Copy(const X* p) {
    a = p->a;
    b = p->b;
    c = p->c;
    d = p->d;
    e = p->e;
    f = p->f;
    g = p->g;
    h = p->h;
    i = p->i;
    state = 2;
}