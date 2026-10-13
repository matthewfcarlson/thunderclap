class X {
  public:
    char pad[0x10];
    char m10;
    char Set(char v);
};

char X::Set(char v) {
    m10 = v;
    return 1;
}
