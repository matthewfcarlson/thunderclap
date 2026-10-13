class O {
  public:
    char p[0x1b];
    unsigned char F(unsigned char x);
};

unsigned char O::F(unsigned char x) {
    p[0x1b] = x;
    return 1;
}
