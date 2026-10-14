class C_115630 {
  public:
    char pad[0x28];
    unsigned char m;
    unsigned char Set(unsigned char x);
};

unsigned char C_115630::Set(unsigned char x) {
    m = x;
    return 1;
}
