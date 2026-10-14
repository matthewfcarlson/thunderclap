class X {
  public:
    char Set(char v);
    char Pad[0x16];
    char m16;
};

char X::Set(char v) {
    m16 = v;
    return 1;
}
