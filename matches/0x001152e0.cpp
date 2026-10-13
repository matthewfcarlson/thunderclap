class O {
  public:
    char m[0x18];
    int m18;
    unsigned char f(int x);
};
unsigned char O::f(int x) {
    m18 = x;
    return 1;
}