class X_17f470 {
  public:
    char pad[0xc];
    unsigned char m;
    unsigned char Set(unsigned char v);
};

unsigned char X_17f470::Set(unsigned char v) {
    m = v;
    return 1;
}
