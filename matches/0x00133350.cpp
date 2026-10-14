class X_133350 {
  public:
    char pad[0x14];
    int m14;
    unsigned char Set(int x);
};

unsigned char X_133350::Set(int x) {
    m14 = x;
    return 1;
}
