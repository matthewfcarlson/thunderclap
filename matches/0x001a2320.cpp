class O {
  public:
    char pad[0x52];
    unsigned char m;
    unsigned char Fn(unsigned char x);
};

unsigned char O::Fn(unsigned char x) {
    m = x;
    return 1;
}
