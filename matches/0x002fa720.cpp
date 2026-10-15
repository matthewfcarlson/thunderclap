class Thing {
  public:
    volatile int a, b, c;
    char d, e, f, g;
    volatile short h, i, j, k;
    Thing();
};
Thing::Thing() {
    h = 0;
    i = 1;
    j = 2;
    c = -1;
    b = -1;
    a = -1;
    f = 0;
    e = 0;
    d = 0;
    g = 0;
    k = 0;
}