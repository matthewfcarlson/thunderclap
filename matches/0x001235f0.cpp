class X {
  public:
    char pad[0x2c];
    unsigned char m2c;
    unsigned char Set(unsigned char v);
};

unsigned char X::Set(unsigned char v) {
    m2c = v;
    return 1;
}
