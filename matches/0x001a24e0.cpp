class X_1a24e0 {
  public:
    char pad[0x88];
    char value;
    char Set(char c);
};

char X_1a24e0::Set(char c) {
    value = c;
    return 1;
}
