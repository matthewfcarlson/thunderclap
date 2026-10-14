class C_123670 {
  public:
    char pad[0x15];
    char field;
    unsigned char Set(unsigned char x);
};

unsigned char C_123670::Set(unsigned char x) {
    field = x;
    return 1;
}
