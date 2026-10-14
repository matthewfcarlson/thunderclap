class X_18caf0 {
  public:
    char pad[0x18];
    char m18;
    char Set(char c);
};

char X_18caf0::Set(char c) {
    m18 = c;
    return 1;
}
