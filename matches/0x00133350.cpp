class X {
  public:
    char pad[0x14];
    int m14;
    unsigned char Set(int x);
};

unsigned char X::Set(int x) {
    m14 = x;
    return 1;
}
