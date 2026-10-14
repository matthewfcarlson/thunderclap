class X {
  public:
    char pad[0x74];
    char f;
    char Set(char c);
};

char X::Set(char c) {
    f = c;
    return 1;
}
