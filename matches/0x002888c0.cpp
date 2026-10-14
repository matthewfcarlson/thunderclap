class C_2888c0 {
  public:
    char pad[0x10];
    volatile unsigned a[2];
    volatile unsigned b[2];
    int f(unsigned n, unsigned x);
};
int C_2888c0::f(unsigned n, unsigned x) {
    if (n > 0) {
        unsigned i = (x != 7);
        unsigned t = (a[i] + x) & ~x;
        unsigned r = b[i] + t;
        a[i] = t + n;
        return r;
    }
    return 0;
}