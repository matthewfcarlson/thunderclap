class X_14c630 {
  public:
    char pad[0x1c];
    unsigned char m1c;
    unsigned char Set(unsigned char x);
};
unsigned char X_14c630::Set(unsigned char x) {
    m1c = x;
    return 1;
}
