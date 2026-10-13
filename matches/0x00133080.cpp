class X {
  public:
    char pad[0x1c];
    int m1c;
    unsigned char Set(int value);
};

unsigned char X::Set(int value) {
    m1c = value;
    return 1;
}
