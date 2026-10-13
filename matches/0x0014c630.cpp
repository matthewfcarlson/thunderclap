class X {
  public:
    char pad[0x1c];
    unsigned char m1c;
    unsigned char Set(unsigned char x);
};
unsigned char X::Set(unsigned char x) {
    m1c = x;
    return 1;
}
