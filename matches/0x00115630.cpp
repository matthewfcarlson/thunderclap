class C {
  public:
    char pad[0x28];
    unsigned char m;
    unsigned char Set(unsigned char x);
};

unsigned char C::Set(unsigned char x) {
    m = x;
    return 1;
}
