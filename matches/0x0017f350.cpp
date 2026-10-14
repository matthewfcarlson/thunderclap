class X_17f350 {
  public:
    char Set(unsigned char b);
    char pad[0x15];
    unsigned char value;
};

char X_17f350::Set(unsigned char b) {
    value = b;
    return 1;
}
