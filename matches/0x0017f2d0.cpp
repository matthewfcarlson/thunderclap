class O_17f2d0 {
  public:
    char pad[0x10];
    unsigned char v;
    unsigned char Set(char x);
};

unsigned char O_17f2d0::Set(char x) {
    v = x;
    return 1;
}
