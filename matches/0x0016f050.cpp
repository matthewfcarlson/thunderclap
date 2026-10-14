class X {
  public:
    char Set(char b);
    char pad[0x54];
    char m54;
};

char X::Set(char b) {
    m54 = b;
    return 1;
}
