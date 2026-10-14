class O_1a2320 {
  public:
    char pad[0x52];
    unsigned char m;
    unsigned char Fn(unsigned char x);
};

unsigned char O_1a2320::Fn(unsigned char x) {
    m = x;
    return 1;
}
