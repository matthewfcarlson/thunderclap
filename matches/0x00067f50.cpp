class X {
  public:
    char pad[0x20];
    char m20;
    char Set(char v);
};

char X::Set(char v) {
    m20 = v;
    return 1;
}
