class O {
  public:
    char pad[0x58];
    unsigned char m58;
    char Set(unsigned char x);
};

char O::Set(unsigned char x) {
    m58 = x;
    return 1;
}
