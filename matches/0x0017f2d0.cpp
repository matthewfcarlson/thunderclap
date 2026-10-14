class O {
  public:
    char pad[0x10];
    unsigned char v;
    unsigned char Set(char x);
};

unsigned char O::Set(char x) {
    v = x;
    return 1;
}
