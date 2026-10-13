class X {
  public:
    char Set(char b);
    char pad[0x10];
    char m10;
};

char X::Set(char b) {
    m10 = b;
    return 1;
}
