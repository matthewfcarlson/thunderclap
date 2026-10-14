class X {
  public:
    char pad[0x88];
    char value;
    char Set(char c);
};

char X::Set(char c) {
    value = c;
    return 1;
}
