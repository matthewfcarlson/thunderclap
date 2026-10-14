class X_1235f0 {
  public:
    char pad[0x2c];
    unsigned char m2c;
    unsigned char Set(unsigned char v);
};

unsigned char X_1235f0::Set(unsigned char v) {
    m2c = v;
    return 1;
}
