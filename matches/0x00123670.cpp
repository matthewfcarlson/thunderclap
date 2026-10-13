class C {
  public:
    char pad[0x15];
    char field;
    unsigned char Set(unsigned char x);
};

unsigned char C::Set(unsigned char x) {
    field = x;
    return 1;
}
