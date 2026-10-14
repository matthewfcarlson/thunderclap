class X_11b8d0 {
  public:
    char pad[0x1c];
    char m;
    char Set(char c);
};

char X_11b8d0::Set(char c) {
    m = c;
    return 1;
}