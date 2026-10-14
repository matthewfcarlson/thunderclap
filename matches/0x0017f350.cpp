class X {
  public:
    char Set(unsigned char b);
    char pad[0x15];
    unsigned char value;
};

char X::Set(unsigned char b) {
    value = b;
    return 1;
}
