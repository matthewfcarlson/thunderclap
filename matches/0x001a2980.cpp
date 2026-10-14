class X {
  public:
    char pad[0x119];
    unsigned char m;
    unsigned char Set(unsigned char v);
};
unsigned char X::Set(unsigned char v) {
    m = v;
    return 1;
}