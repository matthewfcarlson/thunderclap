class X_1931c0 {
  public:
    char pad[0x74];
    char f;
    char Set(char c);
};

char X_1931c0::Set(char c) {
    f = c;
    return 1;
}
