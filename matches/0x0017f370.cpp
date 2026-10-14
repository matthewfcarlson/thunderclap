class X_17f370 {
  public:
    char pad[0x16];
    char m;
    char Set(char c);
};

char X_17f370::Set(char c) {
    m = c;
    return 1;
}
